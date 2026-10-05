-include Makefile.prj

Makefile.prj: project.tcl
	@bdw_makegen project.tcl -s

clean: clean_all
	@rm -rf Makefile.prj
	@rm -f transcript vsim* *.wlf debussy.rc
	@rm -f *~ *.bak *.BAK
	@rm -rf work debussyLog vfastLog
