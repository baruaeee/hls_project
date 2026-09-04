/****************************************************************************
*
*  Copyright (c) 2015, Cadence Design Systems. All Rights Reserved.
*
*  This file contains confidential information that may not be
*  distributed under any circumstances without the written permision
*  of Cadence Design Systems.
*
****************************************************************************/
/****************************************************************************
*
* This file is used to wrap the three different versions of the DUT
* block called "fir_filter". By default, it will include the behavioral
* model. Otherwise, it will include the RTL C++ or the RTL Verilog
* depending on the definition of either of "RTL" or "COSIM".
*
****************************************************************************/

#if defined(STRATUS_VLG)


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#include	"fir_filter_rtl.cpp"

#else 

#if defined(BDW_HUB)

#define SC_INCLUDE_DYNAMIC_PROCESSES 1
#include "esc.h"

#if defined(BDW_RTL)

#define BDW_AUTO_KNOWN 1 


#ifndef BDW_PORTS_ONLY
#define BDW_PORTS_ONLY 1
#endif


#undef fir_filter
#define fir_filter fir_filter_rtl
#	include	"fir_filter_rtl.cpp"
#undef fir_filter


#ifdef BDW_PORTS_ONLY
#undef BDW_PORTS_ONLY
#endif



#elif defined(BDW_HOIST) 
#else

#endif

#include	"fir_filter_cosim.h"




// Include the source for the behavioral model so it will be compiled.
#include	"/home/ipad/HLS_Thesis/Stratus_HLS/Simple_FIR/fir_filter.cpp"


#define		fir_filter_INTERNAL


#include	"fir_filter_wrap.h"


#define MAX_SIMCONFIG_LENGTH 128

#if BDW_WRITEFSDB == 1

#if (defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102
#include "fsdb_nc_mix.h"
#else
#if SYSTEMC_VERSION >= 20120701
#include "fsdb_osci.h"
#else
#include "fsdb_trace_file.h"
#endif
#endif 
#if BDW_USE_SCV
#include "scv.h"
#include "scv_tr_fsdb.h"
#endif

#endif /* BDW_WRITEFSDB */

inline void esc_open_fsdb_trace( const char *file_name = "systemc" );
inline void esc_close_fsdb_trace();
inline void esc_close_fsdb_scv_trace();

// The following threads are used to connect structured ports to the actual
// RTL ports
void fir_filter_wrapper::thread_x_value()
{
   x_value = x.read().value;
}
void fir_filter_wrapper::thread_y()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = y_value.read();
   y.write(tmp);
}
void fir_filter_wrapper::thread_h_value_0()
{
   h_value_0 = h[0].read().value;
}
void fir_filter_wrapper::thread_h_value_1()
{
   h_value_1 = h[1].read().value;
}
void fir_filter_wrapper::thread_h_value_2()
{
   h_value_2 = h[2].read().value;
}
void fir_filter_wrapper::thread_h_value_3()
{
   h_value_3 = h[3].read().value;
}


const char * fir_filter_wrapper::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum fir_filter_wrapper::Representation fir_filter_wrapper::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "fir_filter", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound ) {
		return BDWRep_Behavioral;
	} else if ( err == qbhErrorBadInstName ) {
		if (instName && *instName) {
			const char* leaf = strrchr( instName, '.' ) + 1;
			esc_report_error( esc_warning, "Instance names were specified for module '%s' in simConfig '%s', but they did not "
			                    "match the actal instance names in the RTL.  Try '%s' or '%s'. Simulating '%s' as BEH.\n",
								 "fir_filter", simConfig, instName, leaf,  "fir_filter" );
		}
		return BDWRep_Behavioral;
	}

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
    {
        exit(1);
    }

	return BDWRep_None;
}

void fir_filter_wrapper::InitInstances(  )
{
    enum fir_filter_wrapper::Representation rep =
		fir_filter_wrapper::lookupRepresentation( name() );

	esc_log_wrapper_inst( "fir_filter" );
	esc_log_representation( "fir_filter", name(), rep );


	switch ( rep )
	{
		case BDWRep_Gates:
		    fir_filter_cosim0 = new fir_filter_cosim( "fir_filter" );

		    fir_filter_cosim0->clk(clk);
		    fir_filter_cosim0->rst(rst);
		    fir_filter_cosim0->x_vld(x_vld);
		    fir_filter_cosim0->x_value(x_value);
		    fir_filter_cosim0->y_vld(y_vld);
		    fir_filter_cosim0->y_value(y_value);
		    fir_filter_cosim0->h_value_0(h_value_0);
		    fir_filter_cosim0->h_value_1(h_value_1);
		    fir_filter_cosim0->h_value_2(h_value_2);
		    fir_filter_cosim0->h_value_3(h_value_3);

			break;
		case BDWRep_RTL_HDL:
		    fir_filter_cosim0 = new fir_filter_cosim( "fir_filter" );

		    fir_filter_cosim0->clk(clk);
		    fir_filter_cosim0->rst(rst);
		    fir_filter_cosim0->x_vld(x_vld);
		    fir_filter_cosim0->x_value(x_value);
		    fir_filter_cosim0->y_vld(y_vld);
		    fir_filter_cosim0->y_value(y_value);
		    fir_filter_cosim0->h_value_0(h_value_0);
		    fir_filter_cosim0->h_value_1(h_value_1);
		    fir_filter_cosim0->h_value_2(h_value_2);
		    fir_filter_cosim0->h_value_3(h_value_3);

			break;
#if defined(BDW_RTL)
		case BDWRep_RTL_C:
		    fir_filter_rtl0 = new fir_filter_rtl( "fir_filter" );

		    fir_filter_rtl0->clk(clk);
		    fir_filter_rtl0->rst(rst);
		    fir_filter_rtl0->x_vld(x_vld);
		    fir_filter_rtl0->x_value(x_value);
		    fir_filter_rtl0->y_vld(y_vld);
		    fir_filter_rtl0->y_value(y_value);
		    fir_filter_rtl0->h_value_0(h_value_0);
		    fir_filter_rtl0->h_value_1(h_value_1);
		    fir_filter_rtl0->h_value_2(h_value_2);
		    fir_filter_rtl0->h_value_3(h_value_3);


			{
			const char *simConfig = fir_filter_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    fir_filter0 = new fir_filter( "fir_filter" );

		    fir_filter0->clk(clk);
		    fir_filter0->rst(rst);
		    fir_filter0->x_vld(x_vld);
		    fir_filter0->x(x);
		    fir_filter0->y_vld(y_vld);
		    fir_filter0->y(y);
		    fir_filter0->h[0](h[0]);
		    fir_filter0->h[1](h[1]);
		    fir_filter0->h[2](h[2]);
		    fir_filter0->h[3](h[3]);


			{
			const char *simConfig = fir_filter_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void fir_filter_wrapper::InitThreads()
{
	if ( !isBEH() )
	{
		SC_METHOD(thread_x_value);
		  sensitive << x;
		SC_METHOD(thread_y);
		  sensitive << y_value;
		SC_METHOD(thread_h_value_0);
		  sensitive << h[0];
		SC_METHOD(thread_h_value_1);
		  sensitive << h[1];
		SC_METHOD(thread_h_value_2);
		  sensitive << h[2];
		SC_METHOD(thread_h_value_3);
		  sensitive << h[3];

	}
}

void fir_filter_wrapper::start_of_simulation()
{

#include <fir_filter_trace.h>

        esc_multiple_writers_warning();
}

void fir_filter_wrapper::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void fir_filter_wrapper::end_of_simulation()
{
      CloseTrace();
}



void fir_filter_wrapper::DeleteInstances()
{
    if (fir_filter0)
    {
        delete fir_filter0;
        fir_filter0 = 0;
    }
    if (fir_filter_cosim0)
    {
        delete fir_filter_cosim0;
        fir_filter_cosim0 = 0;
    }
  #if defined(BDW_RTL)
    if (fir_filter_rtl0)
    {
        delete fir_filter_rtl0;
        fir_filter_rtl0 = 0;
    }
#endif
}

// The following threads are used to connect RTL ports to the actual
// structured ports
void fir_filter_wrapper_r::thread_x()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = x_value.read();
   x.write(tmp);
}
void fir_filter_wrapper_r::thread_y_value()
{
   y_value = y.read().value;
}
void fir_filter_wrapper_r::thread_h_0()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_0.read();
   h[0].write(tmp);
}
void fir_filter_wrapper_r::thread_h_1()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_1.read();
   h[1].write(tmp);
}
void fir_filter_wrapper_r::thread_h_2()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_2.read();
   h[2].write(tmp);
}
void fir_filter_wrapper_r::thread_h_3()
{
   cynw_fixed <(int)16, (int)8, (sc_dt::sc_q_mode)0, (sc_dt::sc_o_mode)0, (int)0 > tmp;
   tmp.value = h_value_3.read();
   h[3].write(tmp);
}


const char * fir_filter_wrapper_r::simConfigName()
{
	static char defineBuf[MAX_SIMCONFIG_LENGTH];
	const char *simConfig = NULL;
	if ( qbhGetDefine( "BDW_SIM_CONFIG", defineBuf, MAX_SIMCONFIG_LENGTH ) == qbhOK )
	{
		simConfig = defineBuf;
	}
	else
	{
		simConfig = getenv( "BDW_SIM_CONFIG" );
	}

	if ( simConfig == NULL )
	{
		esc_report_error( esc_fatal, "BDW_SIM_CONFIG needs to be set" );
	}

	return simConfig;
}

enum fir_filter_wrapper_r::Representation fir_filter_wrapper_r::lookupRepresentation( const char* instName )
{
	const char *simConfig = simConfigName();

	if ( simConfig == NULL )
		return BDWRep_None;

	Representation result;

	qbhProjectHandle hProj;
	qbhError err = qbhGetCurrentProject( &hProj );
	if ( err == qbhErrorNoProject )
	{
		err = qbhOpenProject( "project.tcl", &hProj );

		if ( err != qbhOK )
		{
			esc_report_error( esc_fatal, "could not open project file %s",
							  "project.tcl" );
			return BDWRep_None;
		}
	}

	int iresult = 0;
	err = qbhGetRepresentation(hProj, "fir_filter", simConfig, instName, &iresult );
	result = (Representation)iresult;

	if ( err == qbhOK )
		return result;

	// If this module isn't mentioned in the simConfig, assume it's behavioral.
	if ( err == qbhErrorNotFound )
		return BDWRep_Behavioral;

    // If we couldn't get a license, then just exit.
    if ( err == qbhErrorNoLicense )
    {
        exit(1);
    }

	return BDWRep_None;
}

void fir_filter_wrapper_r::InitInstances()
{
    enum fir_filter_wrapper_r::Representation rep =
		fir_filter_wrapper_r::lookupRepresentation( name() );

	esc_log_wrapper_inst( "fir_filter" );
	esc_log_representation( "fir_filter", name(), rep );

	switch ( rep )
	{
		case BDWRep_Gates:
		    fir_filter_cosim0 = new fir_filter_cosim( "fir_filter" );

		    fir_filter_cosim0->clk(clk);
		    fir_filter_cosim0->rst(rst);
		    fir_filter_cosim0->x_vld(x_vld);
		    fir_filter_cosim0->x_value(x_value);
		    fir_filter_cosim0->y_vld(y_vld);
		    fir_filter_cosim0->y_value(y_value);
		    fir_filter_cosim0->h_value_0(h_value_0);
		    fir_filter_cosim0->h_value_1(h_value_1);
		    fir_filter_cosim0->h_value_2(h_value_2);
		    fir_filter_cosim0->h_value_3(h_value_3);

			break;
		case BDWRep_RTL_HDL:
		    fir_filter_cosim0 = new fir_filter_cosim( "fir_filter" );

		    fir_filter_cosim0->clk(clk);
		    fir_filter_cosim0->rst(rst);
		    fir_filter_cosim0->x_vld(x_vld);
		    fir_filter_cosim0->x_value(x_value);
		    fir_filter_cosim0->y_vld(y_vld);
		    fir_filter_cosim0->y_value(y_value);
		    fir_filter_cosim0->h_value_0(h_value_0);
		    fir_filter_cosim0->h_value_1(h_value_1);
		    fir_filter_cosim0->h_value_2(h_value_2);
		    fir_filter_cosim0->h_value_3(h_value_3);

			break;
#if defined(BDW_RTL)
		case BDWRep_RTL_C:
		    fir_filter_rtl0 = new fir_filter_rtl( "fir_filter" );

		    fir_filter_rtl0->clk(clk);
		    fir_filter_rtl0->rst(rst);
		    fir_filter_rtl0->x_vld(x_vld);
		    fir_filter_rtl0->x_value(x_value);
		    fir_filter_rtl0->y_vld(y_vld);
		    fir_filter_rtl0->y_value(y_value);
		    fir_filter_rtl0->h_value_0(h_value_0);
		    fir_filter_rtl0->h_value_1(h_value_1);
		    fir_filter_rtl0->h_value_2(h_value_2);
		    fir_filter_rtl0->h_value_3(h_value_3);


			{
			const char *simConfig = fir_filter_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
#endif
		case BDWRep_Behavioral:
		    fir_filter0 = new fir_filter( "fir_filter" );

		    fir_filter0->clk(clk);
		    fir_filter0->rst(rst);
		    fir_filter0->x_vld(x_vld);
		    fir_filter0->x(x);
		    fir_filter0->y_vld(y_vld);
		    fir_filter0->y(y);
		    fir_filter0->h[0](h[0]);
		    fir_filter0->h[1](h[1]);
		    fir_filter0->h[2](h[2]);
		    fir_filter0->h[3](h[3]);


			{
			const char *simConfig = fir_filter_wrapper::simConfigName();
			
			if ( simConfig != NULL )
				{
				qbhProjectHandle hProj;
				qbhError err = qbhGetCurrentProject( &hProj );
				if ( err == qbhErrorNoProject )
				{
					err = qbhOpenProject( "project.tcl", &hProj );
			
					if ( err != qbhOK )
					{
						esc_report_error( esc_fatal, "could not open project file %s",
						                                          "project.tcl" );
							return;
					}
				}
			
				if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
					esc_get_vcd_trace_file();
				}
				if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
					esc_get_fsdb_trace_file();
				}
				}
			}

			break;
		case BDWRep_None:
		default:
			esc_report_error( esc_error, "No representation could be determined for simulating instance %s. Please make sure that you used the right name string in the module constructor",
							  name() );
			break;
	}
}

void fir_filter_wrapper_r::InitThreads()
{
	if ( isBEH() ) 
	{
		SC_METHOD(thread_x);
		  sensitive << x_value;
		SC_METHOD(thread_y_value);
		  sensitive << y;
		SC_METHOD(thread_h_0);
		  sensitive << h_value_0;
		SC_METHOD(thread_h_1);
		  sensitive << h_value_1;
		SC_METHOD(thread_h_2);
		  sensitive << h_value_2;
		SC_METHOD(thread_h_3);
		  sensitive << h_value_3;

	}
}

void fir_filter_wrapper_r::start_of_simulation()
{

#include <fir_filter_trace.h>

        esc_multiple_writers_warning();
}

void fir_filter_wrapper_r::CloseTrace()
{
	if ( esc_trace_is_enabled( esc_trace_vcd ) ) {
	esc_close_vcd_trace();
	}
	if ( esc_trace_is_enabled( esc_trace_fsdb ) ) {
		esc_close_fsdb_trace();
		if ( esc_trace_is_enabled( esc_trace_scv ) ) {
			esc_close_fsdb_scv_trace();
		}
	}
}

void fir_filter_wrapper_r::end_of_simulation()
{
      CloseTrace();
}



void fir_filter_wrapper_r::DeleteInstances()
{
    if (fir_filter0)
    {
        delete fir_filter0;
        fir_filter0 = 0;
    }
    if (fir_filter_cosim0)
    {
        delete fir_filter_cosim0;
        fir_filter_cosim0 = 0;
    }
  #if defined(BDW_RTL)
    if (fir_filter_rtl0)
    {
        delete fir_filter_rtl0;
        fir_filter_rtl0 = 0;
    }
#endif
}

#if BDW_WRITEFSDB == 1

inline void esc_open_fsdb_trace( const char *file_name  )
{
	sc_trace_file *fsdb_file;
#if ( (defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) && defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102 ) || SYSTEMC_VERSION >= 20120701
    fsdbDumpfile(file_name);
    esc_set_trace_file( fsdb_file, esc_trace_fsdb );
# else

	// SystemC suffixes .fsdb to filenames automatically. Make sure
	// that doesn't get tacked onto a filename that already has the suffix.
	if ( strrchr( file_name, '.' ) != NULL )
	{
		char *trunc_file_name = new char[strlen(file_name)+1];
		strcpy( trunc_file_name, file_name );

		fsdb_file = new fsdb_trace_file( trunc_file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );

		delete trunc_file_name;
	}
	else
	{
		fsdb_file = new fsdb_trace_file( file_name );
		esc_set_trace_file( fsdb_file, esc_trace_fsdb );
	}
#endif

//
// Novas's SystemC wrapper doesn't have a way to set the time unit as of SystemC 2.1v1.
//
//		((fsdb_trace_file*)fsdb_file)->sc_set_fsdb_time_unit( -12 );
}

inline void esc_close_fsdb_trace()
{
#if ! (((defined(XM_SYSTEMC) || defined(NC_SYSTEMC)) &&  defined(BDW_NCSC_VER) && BDW_NCSC_VER > 102) || SYSTEMC_VERSION >= 20120701)
	fsdb_trace_file * fsdb_file =
		(fsdb_trace_file *)esc_trace_file( esc_trace_fsdb );

	if ( fsdb_file != NULL )
	{
		fsdb_file->CloseFile();
		delete fsdb_file;
		esc_set_trace_file( NULL, esc_trace_fsdb );
	}
#endif
}

#else

inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}

#endif

#if BDW_USE_SCV && BDW_WRITEFSDB == 1
static scv_tr_db* local_fsdb_scv_db = 0;

inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
	// Start SCV logging to FSDB if there is not already a database setup.
    if (!esc_get_scv_tr_db() && esc_trace_is_enabled(esc_trace_scv) )
	{
		scv_startup();
		scv_tr_fsdb_init();

		char* scv_file_name = new char[strlen(file_name) + 1];
		strcpy( scv_file_name, file_name );
		char* fsdb_suffix = strstr( scv_file_name, ".fsdb" );
		if (fsdb_suffix)
			*fsdb_suffix = 0;
		local_fsdb_scv_db = new scv_tr_db(scv_file_name);

		delete [] scv_file_name;
		esc_set_scv_tr_db(local_fsdb_scv_db);
		scv_tr_db::set_default_db(local_fsdb_scv_db);
		local_fsdb_scv_db->set_recording(true);
	}
}

inline void esc_close_fsdb_scv_trace()
{
    if ( local_fsdb_scv_db && (local_fsdb_scv_db == esc_get_scv_tr_db() ) ) 
	{
		delete local_fsdb_scv_db;
		local_fsdb_scv_db = 0;
		esc_set_scv_tr_db(0);
	}
}
#else 
inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

#endif

class fir_filter_wrapper_fsdb_opener {
public:
	fir_filter_wrapper_fsdb_opener() {
		esc_set_open_fsdb_trace( esc_open_fsdb_trace );
		esc_set_open_fsdb_scv_trace( esc_open_fsdb_scv_trace );
	}
};

static fir_filter_wrapper_fsdb_opener
  fir_filter_wrapper_fsdb_opener_inst;

#else

// Visible to uses of the wrapper outside of the BDW environment.
// Only behavioral SystemC simulation is supported.


// Include the source for the behavioral model so it will be compiled.
#include	"/home/ipad/HLS_Thesis/Stratus_HLS/Simple_FIR/fir_filter.cpp"

#define		fir_filter_INTERNAL


#include	"fir_filter_wrap.h"

const char * fir_filter_wrapper::simConfigName()
{
  return "";
}

enum fir_filter_wrapper::Representation fir_filter_wrapper::lookupRepresentation( const char* instName )
{
  return BDWRep_Behavioral;
}

void fir_filter_wrapper::InitInstances(  )
{
	fir_filter0 = new fir_filter( "fir_filter" );

	fir_filter0->clk(clk);
	fir_filter0->rst(rst);
	fir_filter0->x_vld(x_vld);
	fir_filter0->x(x);
	fir_filter0->y_vld(y_vld);
	fir_filter0->y(y);
	fir_filter0->h[0](h[0]);
	fir_filter0->h[1](h[1]);
	fir_filter0->h[2](h[2]);
	fir_filter0->h[3](h[3]);

}

void fir_filter_wrapper::InitThreads()
{
}

void fir_filter_wrapper::CloseTrace()
{
}

void fir_filter_wrapper::DeleteInstances()
{
    if (fir_filter0)
    {
        delete fir_filter0;
        fir_filter0 = 0;
    }
}

void fir_filter_wrapper::start_of_simulation()
{
}

void fir_filter_wrapper::end_of_simulation()
{
}



inline void esc_open_fsdb_trace( const char *file_name )
{
}

inline void esc_close_fsdb_trace()
{
}


inline void esc_open_fsdb_scv_trace( const char *file_name  )
{
}

inline void esc_close_fsdb_scv_trace()
{
}

class fir_filter_wrapper_fsdb_opener {
public:
	fir_filter_wrapper_fsdb_opener() {
	}
};

static fir_filter_wrapper_fsdb_opener
  fir_filter_wrapper_fsdb_opener_inst;

#endif

#endif
