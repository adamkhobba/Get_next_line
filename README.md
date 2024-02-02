# Get_next_line
Get_next_line is a project that I use the system call open with full usage.
add here all you need to know about this project.

# Static Variable
## Description
### Def
**`Static Variable`** : have the property to preserving their even after run the program, a static preserve its previous scope and is not initialized again in the the new scope.
### Syntax
```c
static data_type var_name = value;
```

## where it was allocated 
The static variable are allocated memory in the data segment, not the stack segment.
### the data segment
#### initialized data segment
- This is place when the global variable and static variable, but it was initialized by a value.
- The initialized data segment contain the read-only and read-write area. 
#### Uninitialized
- Contain all the data not initialized for the static and global variable it will be initialize  by 0. 
## note 
- A static variables can only be initialized using a constant literals.
- Static variables should not declared inside a structure. The reason is C compiler. 
# Read
## System call
System calls are that a program makes to the system kernel to provide the services to which the program does not have direct access. 
## File Descriptor
### definition 
A file descriptor is a low-level integer representing a open file in a program, it's a way for a program to identify and access a file or input/output resource.
### File Descriptor table
**`File Descriptor table`** A file descriptor table is the collection of integer array indices that are file descriptors in which elements are pointers to file table entries. One unique file descriptor  table is provided in the operating system for each process. 
## File Table Entry
**`File Table Entry`** file table entries a are a structure In-memory surrogate for an open file, which is created when processing a request to open the file and these entries maintain file position.
# 0, 1, 2 stdin stdout stderr
std* is a files (link file).
**any thing we write it in terminal it's write first in stdout**
# Static var vs Global var
the biggest difference between the static and global variable.
the static variable is defined in the a function or in a block of memory.
but the global var is defined in the hole file .

