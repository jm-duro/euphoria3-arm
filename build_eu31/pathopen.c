// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _21e_path_open(int _name, int _mode)
{
    int _src_file;
    int _path = 0;
    int _full_name = 0;
    int _p;
    int _6927 = 0;
    int _6930;
    int _0, _1, _2;
    

    //     src_file = open(name, mode)
    _src_file = EOpen(_name, _mode);

    //     if src_file != -1 then
    if (_src_file == -1)
        goto L1;

    // 	return src_file        
    DeRefDS(_name);
    DeRefDSi(_mode);
    return _src_file;
L1:

    //     for i = 1 to length(SLASH_CHARS) do
    DeRef(_6927);
    _6927 = SEQ_PTR(_4SLASH_CHARS)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _6927)
            goto L3;

        // 	if find(SLASH_CHARS[i], name) then
        _2 = (int)SEQ_PTR(_4SLASH_CHARS);
        _6930 = (int)*(((s1_ptr)_2)->base + _i);
        _6930 = find(_6930, _name);
        if (_6930 == 0)
            goto L4;

        // 	    return -1
        DeRefDS(_name);
        DeRefDSi(_mode);
        DeRefi(_path);
        DeRefi(_full_name);
        DeRef(_6927);
        return -1;
L4:

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     path = getenv("PATH")
    DeRefi(_path);
    _path = EGetEnv(_6932);

    //     if atom(path) then
    _6930 = IS_ATOM(_path);
    if (_6930 == 0)
        goto L5;

    // 	return -1
    DeRefDS(_name);
    DeRefDSi(_mode);
    DeRefi(_path);
    DeRefi(_full_name);
    DeRef(_6927);
    return -1;
L5:

    //     full_name = ""
    RefDS(_39);
    DeRefi(_full_name);
    _full_name = _39;

    //     p = 1
    _p = 1;

    //     path &= PATH_SEPARATOR -- add end marker
    if (IS_SEQUENCE(_path) && IS_ATOM(_4PATH_SEPARATOR)) {
        Append(&_path, _path, _4PATH_SEPARATOR);
    }
    else if (IS_ATOM(_path) && IS_SEQUENCE(_4PATH_SEPARATOR)) {
    }
    else {
        Concat((object_ptr)&_path, _path, (s1_ptr)_4PATH_SEPARATOR);
    }

    //     while p <= length(path) do
L6:
    _6930 = SEQ_PTR(_path)->length;
    if (_p > _6930)
        goto L7;

    // 	if (length(full_name) = 0 and path[p] = ' ') or path[p] = '\t' then
    _6930 = SEQ_PTR(_full_name)->length;
    _6930 = (_6930 == 0);
    if (_6930 == 0) {
        _6930 = 0;
        goto L8;
    }
    DeRef(_6927);
    _2 = (int)SEQ_PTR(_path);
    _6927 = (int)*(((s1_ptr)_2)->base + _p);
    _6927 = (_6927 == 32);
    _6930 = (_6927 != 0);
L8:
    if (_6930 != 0) {
        goto L9;
    }
    _2 = (int)SEQ_PTR(_path);
    _6930 = (int)*(((s1_ptr)_2)->base + _p);
    _6930 = (_6930 == 9);
LA:
    if (_6930 == 0)
        goto LB;
LC:
    goto L9;
LB:

    // 	elsif path[p] = PATH_SEPARATOR then
    _2 = (int)SEQ_PTR(_path);
    _6930 = (int)*(((s1_ptr)_2)->base + _p);
    if (_6930 != _4PATH_SEPARATOR)
        goto LD;

    // 	    if length(full_name) then
    _6930 = SEQ_PTR(_full_name)->length;
    if (_6930 == 0)
        goto L9;

    // 		while length(full_name) and full_name[$] = ' ' do
LE:
    _6930 = SEQ_PTR(_full_name)->length;
    if (_6930 == 0) {
        goto LF;
    }
    DeRef(_6927);
    _6927 = SEQ_PTR(_full_name)->length;
    _2 = (int)SEQ_PTR(_full_name);
    _6927 = (int)*(((s1_ptr)_2)->base + _6927);
    _6927 = (_6927 == 32);
L10:
    if (_6927 == 0)
        goto LF;

    // 		    full_name = full_name[1..$-1]
    DeRef(_6927);
    _6927 = SEQ_PTR(_full_name)->length;
    _6927 = _6927 - 1;
    rhs_slice_target = (object_ptr)&_full_name;
    RHS_Slice((s1_ptr)_full_name, 1, _6927);

    // 		end while
    goto LE;
LF:

    // 		src_file = open(full_name & SLASH & name, mode)
    {
        int concat_list[3];

        concat_list[0] = _name;
        concat_list[1] = _4SLASH;
        concat_list[2] = _full_name;
        Concat_N((object_ptr)&_6927, concat_list, 3);
    }
    _src_file = EOpen(_6927, _mode);

    // 		if src_file != -1 then
    if (_src_file == -1)
        goto L11;

    // 		    file_name[1] = full_name & SLASH & name          
    {
        int concat_list[3];

        concat_list[0] = _name;
        concat_list[1] = _4SLASH;
        concat_list[2] = _full_name;
        Concat_N((object_ptr)&_6927, concat_list, 3);
    }
    RefDS(_6927);
    _2 = (int)SEQ_PTR(_4file_name);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4file_name = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _6927;
    DeRefDS(_1);

    // 		    return src_file
    DeRefDS(_name);
    DeRefDSi(_mode);
    DeRefi(_path);
    DeRefDSi(_full_name);
    DeRefDS(_6927);
    return _src_file;
    goto L9;
L11:

    // 		    full_name = ""
    RefDS(_39);
    DeRefi(_full_name);
    _full_name = _39;
L12:
L13:
    goto L9;
LD:

    // 	    full_name &= path[p] -- build up the directory name
    DeRef(_6927);
    _2 = (int)SEQ_PTR(_path);
    _6927 = (int)*(((s1_ptr)_2)->base + _p);
    Append(&_full_name, _full_name, _6927);
L9:

    // 	p += 1
    _p = _p + 1;

    //     end while
    goto L6;
L7:

    //     return -1
    DeRefDS(_name);
    DeRefDSi(_mode);
    DeRefi(_path);
    DeRefi(_full_name);
    DeRef(_6927);
    return -1;
    ;
}


