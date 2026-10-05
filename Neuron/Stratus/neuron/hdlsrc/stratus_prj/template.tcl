#
# Template META Data
#

templateFunction func1

templateInterface ifin {
    KIND        cynw_p2p
    FUNCTION    func1
    FUNCTION_TX input
}

templateInterface ifout {
    KIND        cynw_p2p
    FUNCTION    func1
    FUNCTION_TX output
}

templateSrcFiles {
    tb.cc tb.h
    dut.cc dut.h
    system.cc system.h
}

templateProjectFile project.tcl

templateRenameFiles {
    dut {[dutName]}
}
