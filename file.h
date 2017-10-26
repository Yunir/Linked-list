#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef FILE_H
    #define FILE_H

    bool write(struct node*, char*);
    bool read(struct node**, char*);
    bool serialize(struct node*, char*);
    bool deserialize(struct node**, char*);
#endif
