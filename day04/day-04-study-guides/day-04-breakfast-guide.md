## Day 4 Breakfast Study Guide

1. Viewing File Contents

Commands:

    cat: Display and concatenate file contents.
    more: View file contents one page at a time.
    less: View file contents with navigation capabilities.

Examples:

bash

* cat file.txt                # Display the contents of 'file.txt'
* cat file1.txt file2.txt     # Concatenate 'file1.txt' and 'file2.txt' and display the result
* cat file.txt > newfile.txt  # Redirect the contents of 'file.txt' to 'newfile.txt'
* cat file.txt | less         # View the contents of 'file.txt' page by page

* more file.txt               # View 'file.txt' one page at a time
* less file.txt               # View 'file.txt' with navigation capabilities
* less +G file.txt            # Start viewing at the end of the file

Description:

*    cat is useful for displaying and combining file contents.
*    more and less are used for viewing large files, allowing you to scroll through the content.

2. Basic Text Editing with nano and vim

Commands:

*    nano: A simple, user-friendly text editor.
*    vim: A powerful text editor with a steeper learning curve.

Examples:

bash

* nano file.txt               # Open 'file.txt' for editing
* nano +5 file.txt            # Open 'file.txt' and jump to line 5
* nano -c file.txt            # Show line numbers while editing

* vim file.txt                # Open 'file.txt' in vim
* vim +5 file.txt             # Open 'file.txt' and jump to line 5
* :wq                         # Save changes and exit vim
* :q!                         # Quit vim without saving changes

Description:

*    nano is straightforward and easy for quick edits.
*    vim offers advanced features for editing, but requires practice to master.

3. Searching within Files with grep

Commands:

*    grep: Search for text patterns within files.

Examples:

bash

* grep 'pattern' file.txt      # Search for 'pattern' in 'file.txt'
* grep -r 'pattern' directory/ # Recursively search for 'pattern' in 'directory/'
* grep -i 'pattern' file.txt   # Perform a case-insensitive search

Description:

*    grep is essential for searching text within files, and supports various options for customization.

4. Editing Files with sed

Commands:

*    sed: Stream editor for basic text transformations.

Examples:

bash

* sed 's/old/new/' file.txt    # Replace 'old' with 'new' in 'file.txt'
* sed -i 's/old/new/' file.txt  # Edit 'file.txt' in-place to replace 'old' with 'new'
* sed -n '1,5p' file.txt       # Print lines 1 through 5 of 'file.txt'

Description:

*    sed is used for performing text substitutions and transformations in a stream or file.

This guide provides a solid foundation for understanding file viewing and editing. Mastery of these commands will greatly enhance your efficiency in managing and manipulating files on a Linux system. Happy learning!
