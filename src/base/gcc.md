If you only want some of the stages of compilation, you can use -x (or filename suffixes) to tell gcc where to start, and one of the options -c,
       -S, or -E to say where gcc is to stop.  Note that some combinations (for example, -x cpp-output -E) instruct gcc to do nothing at all.

       -c  Compile or assemble the source files, but do not link.  The linking stage simply is not done.  The ultimate output is in the form of an
           object file for each source file.

           By default, the object file name for a source file is made by replacing the suffix .c, .i, .s, etc., with .o.

           Unrecognized input files, not requiring compilation or assembly, are ignored.

       -S  Stop after the stage of compilation proper; do not assemble.  The output is in the form of an assembler code file for each non-assembler
           input file specified.

           By default, the assembler file name for a source file is made by replacing the suffix .c, .i, etc., with .s.

           Input files that don't require compilation are ignored.

       -E  Stop after the preprocessing stage; do not run the compiler proper.  The output is in the form of preprocessed source code, which is sent to
           the standard output.

           Input files that don't require preprocessing are ignored.

       -o file
           Place output in file file.  This applies to whatever sort of output is being produced, whether it be an executable file, an object file, an
           assembler file or preprocessed C code.

           If -o is not specified, the default is to put an executable file in a.out, the object file for source.suffix in source.o, its assembler file
           in source.s, a precompiled header file in source.suffix.gch, and all preprocessed C source on standard output.

       -v  Print (on standard error output) the commands executed to run the stages of compilation.  Also print the version number of the compiler
           driver program and of the preprocessor and the compiler proper.