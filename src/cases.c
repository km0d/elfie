/**
 * @file cases.c
 * @author 0xff (0xff@0xff.0xff) 
 * @brief All the possible cases go in here.
 * @version 0.1
 * @date 2022-09-08
 * 
 * @copyright Copyright (c) 2022 0xff
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "all.h"

/**
 * @brief Get the file type.
 * 
 * @param elf A pointer to the struct.
 * @return const char* The file type.
 */

static const char *get_file_type(elf_t *elf) {
  switch (elf->elf_header->e_type) {
    case ET_NONE: return ("NONE (None)"); break;
    case ET_REL:  return ("REL (Relocatable file)"); break;
    case ET_EXEC: return ("EXEC (Executable file)"); break;
    case ET_DYN:  return ("DYN (PIE/Shared object file)"); break;
    case ET_CORE: return ("CORE (Core file)"); break;
    default:      return ("Invalid file type."); break;
  }
}

/**
 * @brief Get the machine name.
 * 
 * @param elf A pointer to the struct.
 * @return const char* The machine name.
 */

static const char *get_machine_name(elf_t *elf) {
  switch (elf->elf_header->e_machine) {
    case EM_NONE:		         return ("None"); break;
    case EM_M32:		         return ("WE32100"); break;
    case EM_SPARC:		       return ("Sparc"); break;
    case EM_386:		         return ("Intel 80386"); break;
    case EM_68K:		         return ("MC68000"); break;
    case EM_88K:		         return ("MC88000"); break;
    case EM_IAMCU:		       return ("Intel MCU"); break;
    case EM_860:		         return ("Intel 80860"); break;
    case EM_MIPS:		         return ("MIPS R3000"); break;
    case EM_S370:		         return ("IBM System/370"); break;
    case EM_MIPS_RS3_LE:	   return ("MIPS R4000 big-endian"); break;
    case EM_PARISC:		       return ("HPPA"); break;
    case EM_SPARC32PLUS:	   return ("Sparc v8+"); break;
    case EM_960:		         return ("Intel 80960"); break;
    case EM_PPC:		         return ("PowerPC"); break;
    case EM_PPC64:         	 return ("PowerPC64"); break;
    case EM_S390:	         	 return ("IBM S/390"); break;
    case EM_SPU:		         return ("SPU"); break;
    case EM_V800:	         	 return ("Renesas V850 (using RH850 ABI)"); break;
    case EM_FR20:	         	 return ("Fujitsu FR20"); break;
    case EM_RH32:	         	 return ("TRW RH32"); break;
    case EM_ARM:		         return ("ARM"); break;
    case EM_SH:			         return ("Renesas / SuperH SH"); break;
    case EM_SPARCV9:		     return ("Sparc v9"); break;
    case EM_TRICORE:		     return ("Siemens Tricore"); break;
    case EM_ARC:		         return ("ARC"); break;
    case EM_H8_300:		       return ("Renesas H8/300"); break;
    case EM_H8_300H:		     return ("Renesas H8/300H"); break;
    case EM_H8S:	           return ("Renesas H8S"); break;
    case EM_H8_500:		       return ("Renesas H8/500"); break;
    case EM_IA_64:		       return ("Intel IA-64"); break;
    case EM_MIPS_X:		       return ("Stanford MIPS-X"); break;
    case EM_COLDFIRE:		     return ("Motorola Coldfire"); break;
    case EM_68HC12:		       return ("Motorola MC68HC12 Microcontroller"); break;
    case EM_MMA:		         return ("Fujitsu Multimedia Accelerator"); break;
    case EM_PCP:		         return ("Siemens PCP"); break;
    case EM_NCPU:	         	 return ("Sony nCPU embedded RISC processor"); break;
    case EM_NDR1:	         	 return ("Denso NDR1 microprocesspr"); break;
    case EM_STARCORE:		     return ("Motorola Star*Core processor"); break;
    case EM_ME16:		         return ("Toyota ME16 processor"); break;
    case EM_ST100:	         return ("STMicroelectronics ST100 processor"); break;
    case EM_TINYJ:	         return ("Advanced Logic Corp. TinyJ embedded processor"); break;
    case EM_X86_64:        	 return ("Advanced Micro Devices X86-64"); break;
    case EM_PDSP:		         return ("Sony DSP processor"); break;
    case EM_PDP10:	         return ("Digital Equipment Corp. PDP-10"); break;
    case EM_PDP11:	         return ("Digital Equipment Corp. PDP-11"); break;
    case EM_FX66:		         return ("Siemens FX66 microcontroller"); break;
    case EM_ST9PLUS:		     return ("STMicroelectronics ST9+ 8/16 bit microcontroller"); break;
    case EM_ST7:		         return ("STMicroelectronics ST7 8-bit microcontroller"); break;
    case EM_68HC16:		       return ("Motorola MC68HC16 Microcontroller"); break;
    case EM_68HC11:		       return ("Motorola MC68HC11 Microcontroller"); break;
    case EM_68HC08:		       return ("Motorola MC68HC08 Microcontroller"); break;
    case EM_68HC05:		       return ("Motorola MC68HC05 Microcontroller"); break;
    case EM_SVX:		         return ("Silicon Graphics SVx"); break;
    case EM_ST19:	         	 return ("STMicroelectronics ST19 8-bit microcontroller"); break;
    case EM_VAX:		         return ("Digital VAX"); break;
    case EM_CRIS:	         	 return ("Axis Communications 32-bit embedded processor"); break;
    case EM_JAVELIN:		     return ("Infineon Technologies 32-bit embedded cpu"); break;
    case EM_FIREPATH:	     	 return ("Element 14 64-bit DSP processor"); break;
    case EM_ZSP:		         return ("LSI Logic's 16-bit DSP processor"); break;
    case EM_MMIX:	         	 return ("Donald Knuth's educational 64-bit processor"); break;
    case EM_HUANY:         	 return ("Harvard Universitys's machine-independent object format"); break;
    case EM_PRISM:         	 return ("Vitesse Prism"); break;
    case EM_AVR:		         return ("Atmel AVR 8-bit microcontroller"); break;
    case EM_FR30:	         	 return ("Fujitsu FR30"); break;
    case EM_D10V:	         	 return ("d10v"); break;
    case EM_D30V:	         	 return ("d30v"); break;
    case EM_V850:	         	 return ("Renesas V850"); break;
    case EM_M32R:	         	 return ("Renesas M32R (formerly Mitsubishi M32r)"); break;
    case EM_MN10300:		     return ("mn10300"); break;
    case EM_MN10200:		     return ("mn10200"); break;
    case EM_PJ:		           return ("picoJava"); break;
    case EM_ARC_COMPACT:	   return ("ARCompact"); break;
    case EM_XTENSA:		       return ("Tensilica Xtensa Processor"); break;
    case EM_VIDEOCORE:		   return ("Alphamosaic VideoCore processor"); break;
    case EM_TMM_GPP:		     return ("Thompson Multimedia General Purpose Processor"); break;
    case EM_NS32K:		       return ("National Semiconductor 32000 series"); break;
    case EM_TPC:		         return ("Tenor Network TPC processor"); break;
    case EM_SNP1K:	         return ("Trebia SNP 1000 processor"); break;
    case EM_ST200:		       return ("STMicroelectronics ST200 microcontroller"); break;
    case EM_IP2K:		         return ("Ubicom IP2xxx 8-bit microcontrollers"); break;
    case EM_MAX:		         return ("MAX Processor"); break;
    case EM_CR:			         return ("National Semiconductor CompactRISC"); break;
    case EM_F2MC16:		       return ("Fujitsu F2MC16"); break;
    case EM_MSP430:		       return ("Texas Instruments msp430 microcontroller"); break;
    case EM_BLACKFIN:        return ("Analog Devices Blackfin"); break;
    case EM_SE_C33:		       return ("S1C33 Family of Seiko Epson processors"); break;
    case EM_SEP:		         return ("Sharp embedded microprocessor"); break;
    case EM_ARCA:		         return ("Arca RISC microprocessor"); break;
    case EM_UNICORE:         return ("Unicore"); break;
    case EM_EXCESS:        	 return ("eXcess 16/32/64-bit configurable embedded CPU"); break;
    case EM_DXP:		         return ("Icera Semiconductor Inc. Deep Execution Processor"); break;
    case EM_ALTERA_NIOS2:	   return ("Altera Nios II"); break;
    case EM_CRX:		         return ("National Semiconductor CRX microprocessor"); break;
    case EM_XGATE:	         return ("Motorola XGATE embedded processor"); break;
    case EM_C166:            return (""); break;
    case EM_M16C:		         return ("Renesas M16C series microprocessors"); break;
    case EM_DSPIC30F:		     return ("Microchip Technology dsPIC30F Digital Signal Controller"); break;
    case EM_CE:              return ("Freescale Communication Engine RISC core"); break;
    case EM_M32C:	           return ("Renesas M32c"); break;
    case EM_TSK3000:	       return ("Altium TSK3000 core"); break;
    case EM_RS08:		         return ("Freescale RS08 embedded processor"); break;
    case EM_ECOG2:	         return ("Cyan Technology eCOG2 microprocessor"); break;
    case EM_DSP24:	         return ("New Japan Radio (NJR) 24-bit DSP Processor"); break;
    case EM_VIDEOCORE3:		   return ("Broadcom VideoCore III processor"); break;
    case EM_LATTICEMICO32:	 return ("Lattice Mico32"); break;
    case EM_SE_C17:		       return ("Seiko Epson C17 family"); break;
    case EM_TI_C6000:		     return ("Texas Instruments TMS320C6000 DSP family"); break;
    case EM_TI_C2000:		     return ("Texas Instruments TMS320C2000 DSP family"); break;
    case EM_TI_C5500:		     return ("Texas Instruments TMS320C55x DSP family"); break;
    case EM_TI_PRU:		       return ("TI PRU I/O processor"); break;
    case EM_MMDSP_PLUS:		   return ("STMicroelectronics 64bit VLIW Data Signal Processor"); break;
    case EM_CYPRESS_M8C:	   return ("Cypress M8C microprocessor"); break;
    case EM_R32C:		         return ("Renesas R32C series microprocessors"); break;
    case EM_TRIMEDIA:		     return ("NXP Semiconductors TriMedia architecture family"); break;
    case EM_QDSP6:		       return ("QUALCOMM DSP6 Processor"); break;
    case EM_8051:		         return ("Intel 8051 and variants"); break;
    case EM_STXP7X:	       	 return ("STMicroelectronics STxP7x family"); break;
    case EM_NDS32:		       return ("Andes Technology compact code size embedded RISC processor family"); break;
    case EM_ECOG1X:	       	 return ("Cyan Technology eCOG1X family"); break;
    case EM_MAXQ30:	       	 return ("Dallas Semiconductor MAXQ30 Core microcontrollers"); break;
    case EM_XIMO16:	       	 return ("New Japan Radio (NJR) 16-bit DSP Processor"); break;
    case EM_MANIK:		       return ("M2000 Reconfigurable RISC Microprocessor"); break;
    case EM_CRAYNV2:		     return ("Cray Inc. NV2 vector architecture"); break;
    case EM_RX:			         return ("Renesas RX"); break;
    case EM_METAG:		       return ("Imagination Technologies Meta processor architecture"); break;
    case EM_MCST_ELBRUS:	   return ("MCST Elbrus general purpose hardware architecture"); break;
    case EM_ECOG16:		       return ("Cyan Technology eCOG16 family"); break;
    case EM_CR16:            return (""); break;
    case EM_MICROBLAZE:      return (""); break;
    case EM_ETPU:		         return ("Freescale Extended Time Processing Unit"); break;
    case EM_SLE9X:		       return ("Infineon Technologies SLE9X core"); break;
    case EM_AARCH64:		     return ("AArch64"); break;
    case EM_AVR32:		       return ("Atmel Corporation 32-bit microprocessor"); break;
    case EM_STM8:		         return ("STMicroeletronics STM8 8-bit microcontroller"); break;
    case EM_TILE64:		       return ("Tilera TILE64 multicore architecture family"); break;
    case EM_TILEPRO:		     return ("Tilera TILEPro multicore architecture family"); break;
    case EM_CUDA:		         return ("NVIDIA CUDA architecture"); break;
    case EM_TILEGX:		       return ("Tilera TILE-Gx multicore architecture family"); break;
    case EM_CLOUDSHIELD:	   return ("CloudShield architecture family"); break;
    case EM_COREA_1ST:	     return ("KIPO-KAIST Core-A 1st generation processor family"); break;
    case EM_COREA_2ND:	     return ("KIPO-KAIST Core-A 2nd generation processor family"); break;
    case EM_OPEN8:		       return ("Open8 8-bit RISC soft processor core"); break;
    case EM_RL78:		         return ("Renesas RL78"); break;
    case EM_VIDEOCORE5:		   return ("Broadcom VideoCore V processor"); break;
    case EM_56800EX:		     return ("Freescale 56800EX Digital Signal Controller (DSC)"); break;
    case EM_BA1:		         return ("Beyond BA1 CPU architecture"); break;
    case EM_BA2:		         return ("Beyond BA2 CPU architecture"); break;
    case EM_XCORE:		       return ("XMOS xCORE processor family"); break;
    case EM_MCHP_PIC:		     return ("Microchip 8-bit PIC(r) family"); break;
    case EM_INTELGT:		     return ("Intel Graphics Technology"); break;
    case EM_KM32:		         return ("KM211 KM32 32-bit processor"); break;
    case EM_KMX32:	         return ("KM211 KMX32 32-bit processor"); break;
    case EM_KVARC:	         return ("KM211 KVARC processor"); break;
    case EM_CDP:		         return ("Paneve CDP architecture family"); break;
    case EM_COGE:		         return ("Cognitive Smart Memory Processor"); break;
    case EM_COOL:		         return ("Bluechip Systems CoolEngine"); break;
    case EM_NORC:		         return ("Nanoradio Optimized RISC"); break;
    case EM_CSR_KALIMBA:	   return ("CSR Kalimba architecture family"); break;
    case EM_Z80:		         return ("Zilog Z80"); break;
    case EM_VISIUM:		       return ("CDS VISIUMcore processor"); break;
    case EM_FT32:            return ("FTDI Chip FT32"); break;
    case EM_MOXIE:           return ("Moxie"); break;
    case EM_AMDGPU:          return ("AMD GPU"); break;
    case EM_RISCV:         	 return ("RISC-V"); break;
    case EM_BPF:		         return ("Linux BPF"); break;
    case EM_CSKY:		         return ("C-SKY"); break;
    case EM_ALPHA:	         return ("Alpha"); break;
    /* whew... Jesus Christ almighty */
    default:                 return ("Invalid machine name."); break;
  }
}

/**
 * @brief Get the storage class.
 * 
 * @param elf A pointer to the struct.
 * @return const char* The storage class.
 */

static const char *get_storage_class(elf_t *elf) {
  switch (elf->elf_header->e_ident[EI_CLASS]) {
    case ELFCLASSNONE: return ("None"); break;
    case ELFCLASS32:   return ("ELF32"); break;
    case ELFCLASS64:   return ("ELF64"); break;
    default:           return ("Invalid storage class."); break;
  }
}

/**
 * @brief Get the data encoding.
 * 
 * @param elf A pointer to the struct.
 * @return const char* The data encoding.
 */

static const char *get_data_encoding(elf_t *elf) {
  switch (elf->elf_header->e_ident[EI_DATA]) {
    case ELFDATANONE: return ("None"); break;
    case ELFDATA2LSB: return ("2's complement, little endian"); break;
    case ELFDATA2MSB: return ("2's complement, big endian"); break;
    default:          return ("Invalid data encoding."); break;
  }
}

/**
 * @brief Get the OS ABI.
 * 
 * @param elf A pointer to the struct.
 * @return const char* The OS ABI.
 */

static const char *get_os_abi(elf_t *elf) {
  switch (elf->elf_header->e_ident[EI_OSABI]) {
    case ELFOSABI_NONE:		 return ("UNIX - System V"); break;
    case ELFOSABI_HPUX:		 return ("UNIX - HP-UX"); break;
    case ELFOSABI_NETBSD:	 return ("UNIX - NetBSD"); break;
    case ELFOSABI_GNU:		 return ("UNIX - GNU"); break;
    case ELFOSABI_SOLARIS: return ("UNIX - Solaris"); break;
    case ELFOSABI_AIX:		 return ("UNIX - AIX"); break;
    case ELFOSABI_IRIX:		 return ("UNIX - IRIX"); break;
    case ELFOSABI_FREEBSD: return ("UNIX - FreeBSD"); break;
    case ELFOSABI_TRU64:	 return ("UNIX - TRU64"); break;
    case ELFOSABI_MODESTO: return ("Novell - Modesto"); break;
    case ELFOSABI_OPENBSD: return ("UNIX - OpenBSD"); break;
    default:               return ("Invalid ABI."); break;
  }
}

/**
 * @brief Get the program type.
 * 
 * @param p_type The type.
 * @return const char* The program type.
 */

static const char *get_program_type(unsigned long p_type) {
  switch (p_type) {
    case PT_NULL:         return ("NULL"); break;
    case PT_LOAD:         return ("LOAD"); break;
    case PT_DYNAMIC:      return ("DYNAMIC"); break;
    case PT_INTERP:	      return ("INTERP"); break;
    case PT_NOTE:	        return ("NOTE"); break;
    case PT_SHLIB:	      return ("SHLIB"); break;
    case PT_PHDR:	        return ("PHDR"); break;
    case PT_TLS:	        return ("TLS"); break;
    case PT_GNU_EH_FRAME: return ("GNU_EH_FRAME"); break;
    case PT_GNU_STACK:	  return ("GNU_STACK"); break;
    case PT_GNU_RELRO:    return ("GNU_RELRO"); break;
    case PT_GNU_PROPERTY: return ("GNU_PROPERTY"); break;
    default:              return ("Invalid."); break;
  }
}

/**
 * @brief Get the program flags.
 * 
 * @param p_flags The flags.
 * @return const char* The program flags.
 */

static const char *get_program_flags(unsigned long p_flags) {
  switch (p_flags) {
    case PF_X:        return ("E"); break;
    case PF_W:        return ("W"); break;
    case PF_R:        return ("R"); break;
    case PF_X + PF_R: return ("RX"); break;
    case PF_W + PF_R: return ("RW"); break;
    case PF_X + PF_W: return ("WX"); break;
    default:          return ("Invalid."); break;
  }
}

/**
 * @brief Get the section type.
 * 
 * @param sh_type The type.
 * @return const char* The section type.
 */

static const char *get_section_type(unsigned long sh_type) {
  switch (sh_type) {
    case SHT_REL:	      	   return ("SHT_REL"); break;
		case SHT_NULL:		       return ("SHT_NULL"); break;
		case SHT_RELA:		       return ("SHT_RELA"); break;
		case SHT_HASH:		       return ("SHT_HASH"); break;
		case SHT_NOTE:		       return ("SHT_NOTE"); break;
		case SHT_SHLIB:	      	 return ("SHT_SHLIB"); break;
		case SHT_GROUP:          return ("SHT_GROUP"); break;
		case SHT_SYMTAB:      	 return ("SHT_SYMTAB"); break;
		case SHT_STRTAB:      	 return ("SHT_STRTAB"); break;
		case SHT_NOBITS:      	 return ("SHT_NOBITS"); break;
		case SHT_DYNSYM:      	 return ("SHT_DYNSYM"); break;
		case SHT_LOPROC:      	 return ("SHT_LOPROC"); break;
		case SHT_HIPROC:      	 return ("SHT_HIPROC"); break;
		case SHT_LOUSER:      	 return ("SHT_LOUSER"); break;
		case SHT_HIUSER:      	 return ("SHT_HIUSER"); break;
		case SHT_DYNAMIC:        return ("SHT_DYNAMIC"); break;
		case SHT_PROGBITS:	     return ("SHT_PROGBITS"); break;
		case SHT_CHECKSUM:	     return ("SHT_CHECKSUM"); break;
		case SHT_GNU_HASH:	     return ("SHT_GNU_HASH"); break;
		case SHT_FINI_ARRAY:     return ("SHT_FINI_ARRAY"); break;
		case SHT_INIT_ARRAY:     return ("SHT_INIT_ARRAY"); break;
		case SHT_GNU_verdef:	   return ("SHT_GNU_verdef"); break;
		case SHT_GNU_versym:	   return ("SHT_GNU_versym"); break;
		case SHT_GNU_verneed:    return ("SHT_GNU_verneed"); break;
		case SHT_SYMTAB_SHNDX:   return ("SHT_SYMTAB_SHNDX"); break;
		case SHT_PREINIT_ARRAY:  return ("SHT_PREINIT_ARRAY"); break;
		case SHT_GNU_ATTRIBUTES: return ("SHT_GNU_ATTRIBUTES"); break;
		default:		             return ("Invalid."); break;
  }
}

/**
 * @brief Get the section flags.
 * 
 * @param sh_flags The flags.
 * @return const char* The section flags.
 */

static const char *get_section_flags(unsigned long sh_flags) {
  switch (sh_flags) {
    case 0:			                       return ("0"); break;
		case SHF_WRITE:		                 return ("SHF_WRITE"); break;
	  case SHF_ALLOC:                    return ("SHF_ALLOC"); break;
	  case SHF_EXECINSTR:                return ("SHF_EXECINSTR"); break;
	  case SHF_MERGE:		                 return ("SHF_MERGE"); break;
	  case SHF_STRINGS:		               return ("SHF_STRINGS"); break;
	  case SHF_INFO_LINK:		             return ("SHF_INFO_LINK"); break;
	  case SHF_LINK_ORDER:	             return ("SHF_LINK_ORDER"); break;
	  case SHF_OS_NONCONFORMING:         return ("SHF_OS_NONCONFORMING"); break;
	  case SHF_GROUP:		                 return ("SHF_GROUP"); break;
	  case SHF_TLS:		                   return ("SHF_TLS"); break;
	  case SHF_EXCLUDE:		               return ("SHF_EXCLUDE"); break;
	  case SHF_COMPRESSED:	             return ("SHF_COMPRESSED"); break;
    case SHF_WRITE + SHF_ALLOC:        return ("SHF_WRT/ALC"); break;
    case SHF_MERGE + SHF_STRINGS:      return ("SHF_MERG/STR"); break;
		case SHF_WRITE + SHF_MASKPROC:     return ("SHF_WRT/MASK"); break;
		case SHF_ALLOC + SHF_MASKPROC:     return ("SHF_ALC/MASK"); break;
		case SHF_ALLOC + SHF_EXECINSTR:    return ("SHF_ALC/EXECINSTR"); break;
		case SHF_WRITE + SHF_EXECINSTR:    return ("SHF_WRT/EXECINSTR"); break;
		case SHF_ALLOC + SHF_INFO_LINK:    return ("SHF_ALC/INFO_LINK"); break;
		case SHF_MASKPROC + SHF_EXECINSTR: return ("SHF_MASK/EXECINSTR"); break;
    default:                           return ("Invalid."); break;
  }
}

/**
 * @brief Get the symbol type.
 * 
 * @param type The type.
 * @return const char* The symbol type.
 */

static const char *get_symbol_type(unsigned int type) {
  switch (ELF64_ST_TYPE(type)) {
    case STT_NOTYPE:	return ("NOTYPE"); break;
    case STT_OBJECT:	return ("OBJECT"); break;
    case STT_FUNC:	  return ("FUNC"); break;
    case STT_SECTION:	return ("SECTION"); break;
    case STT_FILE:	  return ("FILE"); break;
    case STT_COMMON:	return ("COMMON"); break;
    case STT_TLS:	    return ("TLS"); break;
    case STT_LOPROC:  return ("LOPROC"); break;
    case STT_HIPROC:  return ("HIPROC"); break;
    default:          return ("Invalid."); break;
  }
}

/**
 * @brief Get the symbol bind.
 * 
 * @param bind The bind.
 * @return const char* The symbol bind.
 */

static const char *get_symbol_bind(unsigned int bind) {
  switch (ELF64_ST_BIND(bind)) {
    case STB_LOCAL:	 return ("LOCAL"); break;
    case STB_GLOBAL: return ("GLOBAL"); break;
    case STB_WEAK:	 return ("WEAK"); break;
    case STB_LOPROC: return ("LOPROC"); break;
    case STB_HIPROC: return ("HIPROC"); break;
    default:         return ("Invalid."); break;
  }
}

/**
 * @brief Get the symbol visibility.
 * 
 * @param vis The visibility.
 * @return const char* The symbol visibility.
 */

static const char *get_symbol_vis(unsigned int vis) {
  switch (ELF64_ST_VISIBILITY(vis)) {
    case STV_DEFAULT:	  return ("DEFAULT"); break;
    case STV_INTERNAL:	return ("INTERNAL"); break;
    case STV_HIDDEN:	  return ("HIDDEN"); break;
    case STV_PROTECTED: return ("PROTECTED"); break;
    default:            return ("Invalid."); break;
  }
}

/**
 * @brief Outputs the content of the ELF header.
 * 
 * @param elf A pointer to the struct.
 */

void dump_elf_header(elf_t *elf) {
  puts("ELF Header:");
  printf("Magic: ");

  for (int i = 0; i < EI_NIDENT; ++i)
    printf("%2.2x ", elf->elf_header->e_ident[i]);
  putchar('\n');

  printf("Class:                                          %s\n"
         "Data:                                           %s\n"
         "Version:                                        %d\n"
         "OS/ABI:                                         %s\n"
         "ABI Version:                                    %d\n"
         "Type:                                           %s\n"
         "Machine:                                        %s\n"
         "Version:                                        0x%x\n"
         "Entry:                                          0x%lx\n"
         "Program header table offset:                    %lu\n"
         "Section header table offset:                    %lu\n"
         "Flags:                                          0x%x\n"
         "ELF header size:                                %u\n"
         "ELF entry size:                                 %u\n"
         "Number of ELF entries:                          %u\n"
         "Section header size:                            %u\n"
         "Number of entries in section header table:      %u\n"
         "Section header string table index:              %u\n",
         get_storage_class(elf),
         get_data_encoding(elf),
         elf->elf_header->e_ident[EI_VERSION],
         get_os_abi(elf),
         elf->elf_header->e_ident[EI_ABIVERSION],
         get_file_type(elf),
         get_machine_name(elf),
         elf->elf_header->e_version,
         elf->elf_header->e_entry,
         elf->elf_header->e_phoff,
         elf->elf_header->e_shoff,
         elf->elf_header->e_flags,
         elf->elf_header->e_ehsize,
         elf->elf_header->e_phentsize,
         elf->elf_header->e_phnum,
         elf->elf_header->e_shentsize,
         elf->elf_header->e_shnum,
         elf->elf_header->e_shstrndx
  );
}

/**
 * @brief Outputs the content of the program header.
 * 
 * @param elf A pointer to the struct.
 */

void dump_program_headers(elf_t *elf) {
  printf("ELF file type is %s\n"
         "Entry point is 0x%lx\n"
         "There are %d program headers, starting at offset %ld\n\n",
         get_file_type(elf),
         elf->elf_header->e_entry,
         elf->elf_header->e_phnum,
         elf->elf_header->e_phoff
  );

  puts("Program headers:\n"
       "Type          Offset    VirtAddr    PhysAddr    FileSiz   MemSiz   Flags    Align\n");

  for (int i = 0; i < elf->elf_header->e_phnum; ++i) {
    printf("%-14.14s", get_program_type(elf->elf_program_header[i].p_type));
    printf("0x%6.6lx  0x%8.8lx  0x%8.8lx  0x%5.5lx   0x%5.5lx  %-2s       0x%lx\n",
           elf->elf_program_header[i].p_offset,
           elf->elf_program_header[i].p_vaddr,
           elf->elf_program_header[i].p_paddr,
           elf->elf_program_header[i].p_filesz,
           elf->elf_program_header[i].p_memsz,
           get_program_flags(elf->elf_program_header[i].p_flags),
           elf->elf_program_header[i].p_align
    );
  }
}

/**
 * @brief Dumps the section headers.
 * 
 * @param elf A pointer to the struct.
 */

void dump_section_headers(elf_t *elf) {
  printf("There are %d section headers, starting at offset 0x%ld\n\n",
          elf->elf_header->e_shnum,
          elf->elf_header->e_shoff);
  
  if (elf->elf_header->e_shnum == 1)
    puts("Section Header:");
  else
    puts("Section Headers:");
  
  puts("[Nr] Name                Type              Address   Offset    Size    EntSize   Flags              Link    Info    Align");

  for (int i = 0; i < elf->elf_header->e_shnum; ++i) {
    printf(" %-3d %-19s %-17s 0x%-7lx 0x%6.6lx  %6.6lx  %-9.2lx %-18s %-7u %-6u %2lu\n",
           i,
           elf->elf_section_header[i].sh_name + elf->string_table,
           get_section_type(elf->elf_section_header[i].sh_type),
           elf->elf_section_header[i].sh_addr,
           elf->elf_section_header[i].sh_offset,
           elf->elf_section_header[i].sh_size,
           elf->elf_section_header[i].sh_entsize,
           get_section_flags(elf->elf_section_header[i].sh_flags),
           elf->elf_section_header[i].sh_link,
           elf->elf_section_header[i].sh_info,
           elf->elf_section_header[i].sh_addralign
    );
  }
}

/**
 * @brief Dumps the symbol table.
 * 
 * @param elf A pointer to the struct.
 */

void dump_symbol_table(elf_t *elf) {
  for (int i = 0; i < elf->elf_header->e_shnum; ++i) {
    /* are you... a symbol table...? */
    if (elf->elf_section_header[i].sh_type != SHT_SYMTAB 
        && elf->elf_section_header[i].sh_type != SHT_DYNSYM)
      continue; /* no? mkay... */

    size_t sym_num = elf->elf_section_header[i].sh_size / elf->elf_section_header[i].sh_entsize;
    elf->elf_symbol_table = (Elf64_Sym *)(elf->file + elf->elf_section_header[i].sh_offset);
    char *symbol_table = elf->file + elf->elf_section_header[elf->elf_section_header[i].sh_link].sh_offset;

    printf("Symbol table contains %ld entries:\n", sym_num);
    puts("Num:  Value  Size  Type         Bind           Vis          Ndx        Name");

    for (size_t j = 0; j < sym_num; ++j)
      printf("%-5ld %-6ld 0x%-3lx %-12s %-14s %-12s %-10u %s\n",
             j,
             elf->elf_symbol_table[j].st_value,
             elf->elf_symbol_table[j].st_size,
             get_symbol_type(elf->elf_symbol_table[j].st_info),
             get_symbol_bind(elf->elf_symbol_table[j].st_info),
             get_symbol_vis(elf->elf_symbol_table[j].st_other),
             elf->elf_symbol_table[j].st_shndx,
             symbol_table + elf->elf_symbol_table[j].st_name
      );
    putchar('\n');
  }
}