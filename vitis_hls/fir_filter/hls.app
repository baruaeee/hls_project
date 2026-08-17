<project xmlns="com.autoesl.autopilot.project" name="fir_filter" top="fir_filter" projectType="C/C++">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow name="csim" profile="true" clean="true" csimMode="2" lastCsimMode="2"/>
    </Simulation>
    <files xmlns="">
        <file name="fir_filter.cpp" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="fir_filter.h" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="../../fir_tb.cpp" sc="0" tb="1" cflags="-Wno-unknown-pragmas" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="fir_filter_soln" status="active"/>
    </solutions>
</project>

