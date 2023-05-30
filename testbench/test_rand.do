#!tclsh

set ENEITY_NAME "rand_vhd_tst"
set MODULE_NAME "Clock-based Pseudo Random Number Generator"
set TSET_CASES\
"1. Random number vaires with rising edge"

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
