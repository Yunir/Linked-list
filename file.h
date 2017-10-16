#ifndef FILE_H
    #define FILE_H

    bool write(struct node*, char*);
    bool read(struct node**, char*);
    bool serialize(struct node*, char*);
    bool deserialize(struct node**, char*);
#endif
