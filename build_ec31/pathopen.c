// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _22e_path_open(int _name, int _mode)
{
    int _src_file;
    int _path = 0;
    int _full_name = 0;
    int _p;
    int _10897 = 0;
    int _10900;
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
    DeRef(_10897);
    _10897 = SEQ_PTR(_4SLASH_CHARS)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _10897)
            goto L3;

        // 	if find(SLASH_CHARS[i], name) then
        _2 = (int)SEQ_PTR(_4SLASH_CHARS);
        _10900 = (int)*(((s1_ptr)_2)->base + _i);
        _10900 = find(_10900, _name);
        if (_10900 == 0)
            goto L4;

        // 	    return -1
        DeRefDS(_name);
        DeRefDSi(_mode);
        DeRefi(_path);
        DeRefi(_full_name);
        DeRef(_10897);
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
    _path = EGetEnv(_10820);

    //     if atom(path) then
    _10900 = IS_ATOM(_path);
    if (_10900 == 0)
        goto L5;

    // 	return -1
    DeRefDS(_name);
    DeRefDSi(_mode);
    DeRefi(_path);
    DeRefi(_full_name);
    DeRef(_10897);
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
    _10900 = SEQ_PTR(_path)->length;
    if (_p > _10900)
        goto L7;

    // 	if (length(full_name) = 0 and path[p] = ' ') or path[p] = '\t' then
    _10900 = SEQ_PTR(_full_name)->length;
    _10900 = (_10900 == 0);
    if (_10900 == 0) {
        _10900 = 0;
        goto L8;
    }
    DeRef(_10897);
    _2 = (int)SEQ_PTR(_path);
    _10897 = (int)*(((s1_ptr)_2)->base + _p);
    _10897 = (_10897 == 32);
    _10900 = (_10897 != 0);
L8:
    if (_10900 != 0) {
        goto L9;
    }
    _2 = (int)SEQ_PTR(_path);
    _10900 = (int)*(((s1_ptr)_2)->base + _p);
    _10900 = (_10900 == 9);
LA:
    if (_10900 == 0)
        goto LB;
LC:
    goto L9;
LB:

    // 	elsif path[p] = PATH_SEPARATOR then
    _2 = (int)SEQ_PTR(_path);
    _10900 = (int)*(((s1_ptr)_2)->base + _p);
    if (_10900 != _4PATH_SEPARATOR)
        goto LD;

    // 	    if length(full_name) then
    _10900 = SEQ_PTR(_full_name)->length;
    if (_10900 == 0)
        goto L9;

    // 		while length(full_name) and full_name[$] = ' ' do
LE:
    _10900 = SEQ_PTR(_full_name)->length;
    if (_10900 == 0) {
        goto LF;
    }
    DeRef(_10897);
    _10897 = SEQ_PTR(_full_name)->length;
    _2 = (int)SEQ_PTR(_full_name);
    _10897 = (int)*(((s1_ptr)_2)->base + _10897);
    _10897 = (_10897 == 32);
L10:
    if (_10897 == 0)
        goto LF;

    // 		    full_name = full_name[1..$-1]
    DeRef(_10897);
    _10897 = SEQ_PTR(_full_name)->length;
    _10897 = _10897 - 1;
    rhs_slice_target = (object_ptr)&_full_name;
    RHS_Slice((s1_ptr)_full_name, 1, _10897);

    // 		end while
    goto LE;
LF:

    // 		src_file = open(full_name & SLASH & name, mode)
    {
        int concat_list[3];

        concat_list[0] = _name;
        concat_list[1] = _4SLASH;
        concat_list[2] = _full_name;
        Concat_N((object_ptr)&_10897, concat_list, 3);
    }
    _src_file = EOpen(_10897, _mode);

    // 		if src_file != -1 then
    if (_src_file == -1)
        goto L11;

    // 		    file_name[1] = full_name & SLASH & name          
    {
        int concat_list[3];

        concat_list[0] = _name;
        concat_list[1] = _4SLASH;
        concat_list[2] = _full_name;
        Concat_N((object_ptr)&_10897, concat_list, 3);
    }
    RefDS(_10897);
    _2 = (int)SEQ_PTR(_4file_name);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4file_name = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _10897;
    DeRefDS(_1);

    // 		    return src_file
    DeRefDS(_name);
    DeRefDSi(_mode);
    DeRefi(_path);
    DeRefDSi(_full_name);
    DeRefDS(_10897);
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
    DeRef(_10897);
    _2 = (int)SEQ_PTR(_path);
    _10897 = (int)*(((s1_ptr)_2)->base + _p);
    Append(&_full_name, _full_name, _10897);
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
    DeRef(_10897);
    return -1;
    ;
}


