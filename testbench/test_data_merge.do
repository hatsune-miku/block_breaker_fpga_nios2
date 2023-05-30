#!tclsh

set ENEITY_NAME "data_merge_vhd_tst"
set MODULE_NAME "Data Merger"
set TSET_CASES\
"1. high32bit=11100000000000000000000000000111, mid32bit=00011111111111111111111111111000, low8bit=11110011, expecting result=111000000000000000000000000001110001111111111111111111111111100011110011"

# Quit last sim.
quit -sim

# Compile all files.
project compileall

# Sim entity without optimizing out any signals.
vsim -voptargs=+acc $ENEITY_NAME

# Add waves and start simulation.
add wave *
run 500ns

set overall_result [expr [examine ok] == 1]

# Check
if {$overall_result} {
  tk_messageBox -title "Test Result" -icon info -message "Module Name:\n$MODULE_NAME\n\nTestcases:\n$TSET_CASES\n\nOverall Test Result:\nPass!"
}
else {
  tk_messageBox -title "Test Result" -icon error -message "Module Name:\n$MODULE_NAME\n\nTestcases:\n$TSET_CASES\n\nverall Test Result:\nFail!"
}
