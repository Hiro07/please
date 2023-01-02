# please(1)

## NAME
  please - executes nothing, but you can mention "please" to any commands.

## SYNOPSIS
  please [command ... ]
  
## DESCRIPTION
  This command executes nothing, nothing means this command executes the following arguments as a command, or passes through the pipeline input. 
  But you can mention "please" to any commands.

## EXAMPLES
    $ please ls
  
  Return the result of *ls* command. This can make you fell like you're saying "Please list (the files)."

    $ ls | please
  
  Pass through the result of *ls* command. This is like "List (the files), please"
  
## DOWNLOAD
  Executable binaries
    for Apple Silicon Mac (Mach-O 64-bit executable arm64) : <a id="raw-url" href="https://github.com/Hiro07/please/releases/latest">Latest Release</a>

## Copyright
  2023 Hiroyuki Kikuchi (hjfk07@gmail.com)

## MORE DETAILS
  <a href="https://hilog07.blogspot.com/2022/02/blog-post.html">Joke Command / Meme Command : please
</a>
