# please(1)

## NAME
  please - executes nothing, but you can tell "please" to any commands.

## SYNOPSIS
  please [command ... ]
  
## DESCRIPTION
  This command executes nothing, nothing means this command executes the following arguments as command, and/or passes through the pipeline input.
  But you can tell "please" to any commands.

## EXIT STATUS
  - when no arguments : returns 0
  - when arguments exist : returns the following command's exit code. when opening following command was failed, this returns 1. and when following command did not terminate normally, this returns 1.

## EXAMPLES
    $ please ls
  
  Return the result of *ls* command. This can make you feel like you're saying *"Please list (the files)."*

    $ ls | please
  
  Pass through the result of *ls* command. This is like *"List (the files), please"*
  

    $ ls | please wc
  
  Execute *wc* (words count command) and *wc* will get the *ls* result from pipeline.
  How this works is because of *popen(3)* function.

  >   POPEN(3)
  >
  >     ...
  >     the command's standard input is the same as that of the process that called popen().
  >     ...


  With *please* command's case, this function fortunately and completely fits for the purpose.
  
## DOWNLOAD
  Executable binaries
    for Apple Silicon Mac (Mach-O 64-bit executable arm64) : <a id="raw-url" href="https://github.com/Hiro07/please/releases/latest">Latest Release</a>

## Copyright
  2023 Hiroyuki Kikuchi (hjfk07@gmail.com)

## MORE DETAILS
  <a href="https://hilog07.blogspot.com/2022/02/blog-post.html">Joke Command / Meme Command : please
</a>
