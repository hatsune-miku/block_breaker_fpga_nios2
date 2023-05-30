#!tclsh

set ENEITY_NAME "vga_ctrl_vhd_tst"
set MODULE_NAME "VGA Controller"

# Quit last sim.
quit -sim

# Compile all files.
project compileall

# Sim entity without optimizing out any signals.
vsim -voptargs=+acc $ENEITY_NAME

# Add waves and start simulation.
add wave *
run 500ns

set t1 [expr [examine ok_clk] == 1]
set t2 [expr [examine ok_blankn] == 1]
set t3 [expr [examine ok_syncn] == 1]
set t4 [expr [examine ok_rgb] == 1]

if {$t1} {set d1 "Pass"} else {set d1 "Fail"}
if {$t2} {set d2 "Pass"} else {set d2 "Fail"}
if {$t3} {set d3 "Pass"} else {set d3 "Fail"}
if {$t4} {set d4 "Pass"} else {set d4 "Fail"}

set TSET_CASES\
"1. \[$d1\] Can correctly generate VGA clock
2. \[$d2\] Can correctly set blank_n to One
3. \[$d3\] Can correctly set sync_n to Zero
4. \[$d4\] Can correctly generate white color for the ball"

set overall_result [expr $t1 && $t2 && $t3 && $t4]

# Check
if {$overall_result} {
  tk_messageBox -title "Test Result" -icon info -message "Module Name:\n$MODULE_NAME\n\nTestcases:\n$TSET_CASES\n\nOverall Test Result:\nPass!"
}
else {
  tk_messageBox -title "Test Result" -icon error -message "Module Name:\n$MODULE_NAME\n\nTestcases:\n$TSET_CASES\n\nverall Test Result:\nFail!"
}
