#include "sys/alt_stdio.h"
#include "core_game/core_game.h"
#include "logging/logging.h"


int main() {
  log_info("Block Breaker Game by Zhen Guan, Jiabao Guo");
  log_info("ENGI-9865 Course Design");
  log_info("Memorial University");

  for (;;) {
    cg_main();
  }

  // Event loop never exits.
  for (;;);

  return 0;
}
