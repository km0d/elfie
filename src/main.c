#include "all.h"

arg_t args[] = {
  {"-h", dump_elf_header},
  {"-p", dump_program_headers},
  {"-S", dump_section_headers},
  {"-st", dump_symbol_table}
};

/**
 * @brief Based on the options specified, it will call a certain function.
 * 
 * @param arg The option.
 * @param elf A pointer to the struct.
 */

static bool handler(const char *arg, elf_t *elf) {
  for (unsigned int i = 0; i < sizeof(args)/sizeof(args[0]); ++i) {
    if (strstr(arg, args[i].name)) {
      (args[i].func)(elf);
      return true;
    }
  }
  return false;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <option> <file>\n", argv[0]);
    fprintf(stderr, 
            "-h - Dump ELF header.\n"
            "-p - Dump program headers.\n"
            "-S - Dump section header.\n"
            "-st - Dump symbol table.\n");
    exit(EXIT_FAILURE);
  }

  int fd = open(argv[2], O_RDONLY);

  if (fd == -1) {
    close(fd);
    exit(EXIT_FAILURE);
  }

  elf_t *elf = init_elf(fd);

  if (!handler(argv[1], elf))
    error_handling(fd, elf, elf->file, "Invalid option.");

  destroy_parser(fd, elf->file, elf);
}