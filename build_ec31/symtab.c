// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _10hashfn(int _name)
{
    int _len;
    int _val;
    int _946 = 0;
    int _949 = 0;
    int _0, _1, _2;
    

    //     len = length(name)
    _len = SEQ_PTR(_name)->length;

    //     val = name[len] * 256 + name[1]*2 + len
    _2 = (int)SEQ_PTR(_name);
    _946 = (int)*(((s1_ptr)_2)->base + _len);
    Ref(_946);
    _0 = _946;
    if (IS_ATOM_INT(_946)) {
        if (_946 == (short)_946)
            _946 = _946 * 256;
        else
            _946 = NewDouble(_946 * (double)256);
    }
    else {
        _946 = binary_op(MULTIPLY, _946, 256);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_name);
    _949 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_949);
    _0 = _949;
    if (IS_ATOM_INT(_949) && IS_ATOM_INT(_949)) {
        _949 = _949 + _949;
        if ((long)((unsigned long)_949 + (unsigned long)HIGH_BITS) >= 0) 
            _949 = NewDouble((double)_949);
    }
    else {
        _949 = binary_op(PLUS, _949, _949);
    }
    DeRef(_0);
    _0 = _949;
    if (IS_ATOM_INT(_946) && IS_ATOM_INT(_949)) {
        _949 = _946 + _949;
        if ((long)((unsigned long)_949 + (unsigned long)HIGH_BITS) >= 0) 
            _949 = NewDouble((double)_949);
    }
    else {
        _949 = binary_op(PLUS, _946, _949);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_949)) {
        _val = _949 + _len;
    }
    else {
        _val = binary_op(PLUS, _949, _len);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }

    //     if len >= 4 then
    if (_len < 4)
        goto L1;

    // 	val = val * 64 + name[2]
    DeRef(_949);
    if (_val == (short)_val)
        _949 = _val * 64;
    else
        _949 = NewDouble(_val * (double)64);
    DeRef(_946);
    _2 = (int)SEQ_PTR(_name);
    _946 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_946);
    if (IS_ATOM_INT(_949) && IS_ATOM_INT(_946)) {
        _val = _949 + _946;
    }
    else {
        _val = binary_op(PLUS, _949, _946);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }

    // 	val = val * 64 + name[3]
    DeRef(_946);
    if (_val == (short)_val)
        _946 = _val * 64;
    else
        _946 = NewDouble(_val * (double)64);
    DeRef(_949);
    _2 = (int)SEQ_PTR(_name);
    _949 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_949);
    if (IS_ATOM_INT(_946) && IS_ATOM_INT(_949)) {
        _val = _946 + _949;
    }
    else {
        _val = binary_op(PLUS, _946, _949);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }
    goto L2;
L1:

    //     elsif len >= 3 then
    if (_len < 3)
        goto L3;

    // 	val = val * 64 + name[2]
    DeRef(_949);
    if (_val == (short)_val)
        _949 = _val * 64;
    else
        _949 = NewDouble(_val * (double)64);
    DeRef(_946);
    _2 = (int)SEQ_PTR(_name);
    _946 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_946);
    if (IS_ATOM_INT(_949) && IS_ATOM_INT(_946)) {
        _val = _949 + _946;
    }
    else {
        _val = binary_op(PLUS, _949, _946);
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }
L3:
L2:

    //     return remainder(val, NBUCKETS) + 1
    DeRef(_946);
    _946 = (_val % 2003);
    _946 = _946 + 1;
    DeRefDS(_name);
    DeRef(_949);
    return _946;
    ;
}


int _10NewEntry(int _name, int _varnum, int _scope, int _token, int _hashval, int _samehash, int _type_sym)
{
    int _new = 0;
    int _976;
    int _966 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_varnum)) {
        _1 = (long)(DBL_PTR(_varnum)->dbl);
        DeRefDS(_varnum);
        _varnum = _1;
    }
    if (!IS_ATOM_INT(_scope)) {
        _1 = (long)(DBL_PTR(_scope)->dbl);
        DeRefDS(_scope);
        _scope = _1;
    }
    if (!IS_ATOM_INT(_token)) {
        _1 = (long)(DBL_PTR(_token)->dbl);
        DeRefDS(_token);
        _token = _1;
    }
    if (!IS_ATOM_INT(_hashval)) {
        _1 = (long)(DBL_PTR(_hashval)->dbl);
        DeRefDS(_hashval);
        _hashval = _1;
    }
    if (!IS_ATOM_INT(_samehash)) {
        _1 = (long)(DBL_PTR(_samehash)->dbl);
        DeRefDS(_samehash);
        _samehash = _1;
    }
    if (!IS_ATOM_INT(_type_sym)) {
        _1 = (long)(DBL_PTR(_type_sym)->dbl);
        DeRefDS(_type_sym);
        _type_sym = _1;
    }

    //     if TRANSLATE then

    // 	new = repeat(0, SIZEOF_ROUTINE_ENTRY)
    _new = Repeat(0, 49);
    goto L1;
L2:

    // 	new = repeat(0, SIZEOF_VAR_ENTRY)
    DeRef(_new);
    _new = Repeat(0, 49);
L1:

    //     new[S_NEXT] = 0
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     new[S_NAME] = name
    RefDS(_name);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _name;
    DeRef(_1);

    //     new[S_SCOPE] = scope
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _scope;
    DeRef(_1);

    //     new[S_MODE] = M_NORMAL
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     new[S_USAGE] = U_UNUSED
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     new[S_FILE_NO] = current_file_no
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 6);
    _1 = *(int *)_2;
    *(int *)_2 = _4current_file_no;
    DeRef(_1);

    //     if TRANSLATE then

    // 	new[S_GTYPE] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	new[S_GTYPE_NEW] = TYPE_NULL
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 35);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	new[S_SEQ_ELEM] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	new[S_SEQ_ELEM_NEW] = TYPE_NULL -- starting point for ORing
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	new[S_ARG_TYPE] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 40);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	new[S_ARG_TYPE_NEW] = TYPE_NULL
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 41);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	new[S_ARG_SEQ_ELEM] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 42);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	new[S_ARG_SEQ_ELEM_NEW] = TYPE_NULL
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 43);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	new[S_ARG_MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 44);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	new[S_ARG_MIN_NEW] = -NOVALUE
    DeRef(_966);
    _966 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_966);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 46);
    _1 = *(int *)_2;
    *(int *)_2 = _966;
    DeRef(_1);

    // 	new[S_ARG_SEQ_LEN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 48);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	new[S_ARG_SEQ_LEN_NEW] = -NOVALUE
    DeRefDS(_966);
    _966 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_966);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 49);
    _1 = *(int *)_2;
    *(int *)_2 = _966;
    DeRef(_1);

    // 	new[S_SEQ_LEN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	new[S_SEQ_LEN_NEW] = -NOVALUE -- no idea yet
    DeRefDS(_966);
    _966 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_966);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _966;
    DeRef(_1);

    // 	new[S_NREFS] = 0
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	new[S_ONE_REF] = TRUE          -- assume TRUE until we find otherwise
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	new[S_RI_TARGET] = 0
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 33);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	new[S_OBJ_MIN] = MININT
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = -1073741824;
    DeRef(_1);

    // 	new[S_OBJ_MIN_NEW] = -NOVALUE -- no idea yet
    DeRefDS(_966);
    _966 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_966);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _966;
    DeRef(_1);

    // 	new[S_OBJ_MAX] = MAXINT
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = 1073741823;
    DeRef(_1);

    // 	new[S_OBJ_MAX_NEW] = -NOVALUE -- missing from C code? (not needed)
    DeRefDS(_966);
    _966 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_966);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 39);
    _1 = *(int *)_2;
    *(int *)_2 = _966;
    DeRef(_1);
L3:

    //     new[S_TOKEN] = token
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _token;
    DeRef(_1);

    //     new[S_VARNUM] = varnum
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 12);
    _1 = *(int *)_2;
    *(int *)_2 = _varnum;
    DeRef(_1);

    //     new[S_INITLEVEL] = -1
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 13);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    //     new[S_VTYPE] = type_sym
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_sym;
    DeRef(_1);

    //     new[S_HASHVAL] = hashval
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _hashval;
    DeRef(_1);

    //     new[S_SAMEHASH] = samehash
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _samehash;
    DeRef(_1);

    //     new[S_OBJ] = NOVALUE -- important 
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_new);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _new = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    //     SymTab = append(SymTab, new)
    RefDS(_new);
    Append(&_4SymTab, _4SymTab, _new);

    //     if last_sym then
    if (_10last_sym == 0)
        goto L4;

    // 	SymTab[last_sym][S_NEXT] = length(SymTab)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_10last_sym + ((s1_ptr)_2)->base);
    _976 = SEQ_PTR(_4SymTab)->length;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _976;
    DeRef(_1);
L4:

    //     last_sym = length(SymTab)
    _10last_sym = SEQ_PTR(_4SymTab)->length;

    //     return last_sym
    DeRefDS(_name);
    DeRef(_new);
    DeRef(_966);
    return _10last_sym;
    ;
}


int _10tmp_alloc()
{
    int _new;
    int _1003;
    int _979 = 0;
    int _0, _1, _2, _3;
    

    //     SymTab = append(SymTab, BLANK_ENTRY)
    RefDS(_10BLANK_ENTRY);
    Append(&_4SymTab, _4SymTab, _10BLANK_ENTRY);

    //     new = length(SymTab)
    _new = SEQ_PTR(_4SymTab)->length;

    //     SymTab[new][S_USAGE] = T_UNKNOWN
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);

    //     if TRANSLATE then

    // 	SymTab[new][S_GTYPE] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	SymTab[new][S_OBJ_MIN] = MININT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = -1073741824;
    DeRef(_1);

    // 	SymTab[new][S_OBJ_MAX] = MAXINT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = 1073741823;
    DeRef(_1);

    // 	SymTab[new][S_SEQ_LEN] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	SymTab[new][S_SEQ_ELEM] = TYPE_OBJECT  -- other fields set later
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	if length(temp_name_type)+1 = 8087 then
    _979 = SEQ_PTR(_4temp_name_type)->length;
    _979 = _979 + 1;
    if (_979 != 8087)
        goto L1;

    // 	    temp_name_type = append(temp_name_type, {0, 0})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 0;
    _979 = MAKE_SEQ(_1);
    RefDS(_979);
    Append(&_4temp_name_type, _4temp_name_type, _979);
L1:

    // 	temp_name_type = append(temp_name_type, {TYPE_OBJECT, TYPE_NULL})
    DeRef(_979);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 16;
    ((int *)_2)[2] = 0;
    _979 = MAKE_SEQ(_1);
    RefDS(_979);
    Append(&_4temp_name_type, _4temp_name_type, _979);

    // 	SymTab[new][S_TEMP_NAME] = length(temp_name_type)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_new + ((s1_ptr)_2)->base);
    _1003 = SEQ_PTR(_4temp_name_type)->length;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 31);
    _1 = *(int *)_2;
    *(int *)_2 = _1003;
    DeRef(_1);
L2:

    //     return new
    DeRef(_979);
    return _new;
    ;
}


int _10DefinedYet(int _sym)
{
    int _1013 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    //     if not find(SymTab[sym][S_SCOPE], 
    _2 = (int)SEQ_PTR(_4SymTab);
    _1013 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_1013);
    _0 = _1013;
    _2 = (int)SEQ_PTR(_1013);
    _1013 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1013);
    DeRefDS(_0);
    _0 = _1013;
    _1013 = find(_1013, _1015);
    DeRef(_0);
    if (_1013 != 0)
        goto L1;

    // 	if SymTab[sym][S_FILE_NO] = current_file_no then
    _2 = (int)SEQ_PTR(_4SymTab);
    _1013 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_1013);
    _0 = _1013;
    _2 = (int)SEQ_PTR(_1013);
    _1013 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1013);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _1013, _4current_file_no))
        goto L2;

    // 	    CompileErr(sprintf("attempt to redefine %s", {SymTab[sym][S_NAME]}))
    DeRef(_1013);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1013 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_1013);
    _0 = _1013;
    _2 = (int)SEQ_PTR(_1013);
    _1013 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1013);
    DeRefDS(_0);
    _0 = _1013;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_1013);
    *((int *)(_2+4)) = _1013;
    _1013 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _1013;
    _1013 = EPrintf(-9999999, _1021, _1013);
    DeRefDS(_0);
    RefDS(_1013);
    _6CompileErr(_1013);
L2:
L1:

    // end procedure
    DeRef(_1013);
    return 0;
    ;
}


int _10name_ext(int _s)
{
    int _i;
    int _1026 = 0;
    int _1029 = 0;
    int _0, _1, _2;
    

    //     i = length(s)
    _i = SEQ_PTR(_s)->length;

    //     while i >= 1 and not find(s[i], "/\\:") do  
L1:
    DeRef(_1026);
    _1026 = (_i >= 1);
    if (_1026 == 0) {
        goto L2;
    }
    DeRef(_1029);
    _2 = (int)SEQ_PTR(_s);
    _1029 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_1029);
    _0 = _1029;
    _1029 = find(_1029, _1030);
    DeRef(_0);
    _1029 = (_1029 == 0);
L3:
    if (_1029 == 0)
        goto L2;

    // 	i -= 1
    _i = _i - 1;

    //     end while
    goto L1;
L2:

    //     return s[i+1..$]
    DeRef(_1029);
    _1029 = _i + 1;
    if (_1029 > MAXINT)
        _1029 = NewDouble((double)_1029);
    DeRef(_1026);
    _1026 = SEQ_PTR(_s)->length;
    rhs_slice_target = (object_ptr)&_1026;
    RHS_Slice((s1_ptr)_s, _1029, _1026);
    DeRefDS(_s);
    DeRef(_1029);
    return _1026;
    ;
}


int _10NewStringSym(int _s)
{
    int _p;
    int _tp;
    int _prev;
    int _search_count;
    int _1041 = 0;
    int _1049 = 0;
    int _1050 = 0;
    int _0, _1, _2, _3;
    

    //     tp = literal_init
    _tp = _10literal_init;

    //     prev = 0
    _prev = 0;

    //     search_count = 0
    _search_count = 0;

    //     while tp != 0 do
L1:
    if (_tp == 0)
        goto L2;

    // 	search_count += 1
    _search_count = _search_count + 1;

    // 	if search_count > SEARCH_LIMIT then  -- avoid n-squared algorithm
    if (binary_op_a(LESSEQ, _search_count, _10SEARCH_LIMIT))
        goto L3;

    // 	    exit
    goto L2;
L3:

    // 	if equal(s, SymTab[tp][S_OBJ]) then
    DeRef(_1041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1041 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_1041);
    _0 = _1041;
    _2 = (int)SEQ_PTR(_1041);
    _1041 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1041);
    DeRefDS(_0);
    _0 = _1041;
    if (_s == _1041)
        _1041 = 1;
    else if (IS_ATOM_INT(_s) && IS_ATOM_INT(_1041))
        _1041 = 0;
    else
        _1041 = (compare(_s, _1041) == 0);
    DeRef(_0);
    if (_1041 == 0)
        goto L4;

    // 	    if tp != literal_init then
    if (_tp == _10literal_init)
        goto L5;

    // 		SymTab[prev][S_NEXT] = SymTab[tp][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev + ((s1_ptr)_2)->base);
    DeRef(_1050);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1050 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_1050);
    _0 = _1050;
    _2 = (int)SEQ_PTR(_1050);
    _1050 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1050);
    DeRefDS(_0);
    Ref(_1050);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1050;
    DeRef(_1);

    // 		SymTab[tp][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_tp + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _10literal_init;
    DeRef(_1);

    // 		literal_init = tp
    _10literal_init = _tp;
L5:

    // 	    return tp
    DeRefDS(_s);
    DeRef(_1041);
    DeRef(_1049);
    DeRef(_1050);
    return _tp;
L4:

    // 	prev = tp
    _prev = _tp;

    // 	tp = SymTab[tp][S_NEXT]
    DeRef(_1049);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1049 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_1049);
    _2 = (int)SEQ_PTR(_1049);
    _tp = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_tp))
        _tp = (long)DBL_PTR(_tp)->dbl;

    //     end while
    goto L1;
L2:

    //     p = tmp_alloc()
    _p = _10tmp_alloc();

    //     SymTab[p][S_OBJ] = s
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_s);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _s;
    DeRef(_1);

    //     if TRANSLATE then

    // 	SymTab[p][S_MODE] = M_TEMP    -- override CONSTANT for compile
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[p][S_GTYPE] = TYPE_SEQUENCE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 8;
    DeRef(_1);

    // 	SymTab[p][S_SEQ_LEN] = length(s)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_1041);
    _1041 = SEQ_PTR(_s)->length;
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _1041;
    DeRef(_1);

    // 	if SymTab[p][S_SEQ_LEN] > 0 then
    _2 = (int)SEQ_PTR(_4SymTab);
    _1041 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1041);
    _0 = _1041;
    _2 = (int)SEQ_PTR(_1041);
    _1041 = (int)*(((s1_ptr)_2)->base + 29);
    Ref(_1041);
    DeRefDS(_0);
    if (binary_op_a(LESSEQ, _1041, 0))
        goto L6;

    // 	    SymTab[p][S_SEQ_ELEM] = TYPE_INTEGER
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
    goto L7;
L6:

    // 	    SymTab[p][S_SEQ_ELEM] = TYPE_NULL
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L7:

    // 	c_printf("int _%d;\n", SymTab[p][S_TEMP_NAME])
    DeRef(_1041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1041 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1041);
    _0 = _1041;
    _2 = (int)SEQ_PTR(_1041);
    _1041 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_1041);
    DeRefDS(_0);
    RefDS(_1073);
    Ref(_1041);
    _9c_printf(_1073, _1041);

    // 	c_hprintf("extern int _%d;\n", SymTab[p][S_TEMP_NAME])
    DeRef(_1041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1041 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1041);
    _0 = _1041;
    _2 = (int)SEQ_PTR(_1041);
    _1041 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_1041);
    DeRefDS(_0);
    RefDS(_1076);
    Ref(_1041);
    _9c_hprintf(_1076, _1041);
    goto L8;
L9:

    // 	SymTab[p][S_MODE] = M_CONSTANT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);
L8:

    //     SymTab[p][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _10literal_init;
    DeRef(_1);

    //     literal_init = p
    _10literal_init = _p;

    //     return p
    DeRefDS(_s);
    DeRef(_1041);
    DeRef(_1049);
    DeRef(_1050);
    return _p;
    ;
}


int _10NewIntSym(int _int_val)
{
    int _p;
    int _x;
    int _1087 = 0;
    int _1083;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_int_val)) {
        _1 = (long)(DBL_PTR(_int_val)->dbl);
        DeRefDS(_int_val);
        _int_val = _1;
    }

    //     x = find(int_val, lastintval) 
    _x = find(_int_val, _10lastintval);

    //     if x then
    if (_x == 0)
        goto L1;

    // 	return lastintsym[x]  -- saves space, helps Translator reduce code size
    _2 = (int)SEQ_PTR(_10lastintsym);
    _1083 = (int)*(((s1_ptr)_2)->base + _x);
    return _1083;
    goto L2;
L1:

    // 	p = tmp_alloc()
    _p = _10tmp_alloc();

    // 	SymTab[p][S_MODE] = M_CONSTANT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	SymTab[p][S_OBJ] = int_val
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _int_val;
    DeRef(_1);

    // 	if TRANSLATE then

    // 	    SymTab[p][S_OBJ_MIN] = int_val
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _int_val;
    DeRef(_1);

    // 	    SymTab[p][S_OBJ_MAX] = int_val
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _int_val;
    DeRef(_1);

    // 	    SymTab[p][S_GTYPE] = TYPE_INTEGER
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L3:

    // 	lastintval = prepend(lastintval, int_val)
    Prepend(&_10lastintval, _10lastintval, _int_val);

    // 	lastintsym = prepend(lastintsym, p)
    Prepend(&_10lastintsym, _10lastintsym, _p);

    // 	if length(lastintval) > SEARCH_LIMIT then
    DeRef(_1087);
    _1087 = SEQ_PTR(_10lastintval)->length;
    if (binary_op_a(LESSEQ, _1087, _10SEARCH_LIMIT))
        goto L4;

    // 	    lastintval = lastintval[1..floor(SEARCH_LIMIT/2)]
    if (IS_ATOM_INT(_10SEARCH_LIMIT)) {
        _1087 = _10SEARCH_LIMIT >> 1;
    }
    else {
        _1 = binary_op(DIVIDE, _10SEARCH_LIMIT, 2);
        _1087 = unary_op(FLOOR, _1);
        DeRef(_1);
    }
    rhs_slice_target = (object_ptr)&_10lastintval;
    RHS_Slice((s1_ptr)_10lastintval, 1, _1087);
L4:

    // 	return p
    DeRef(_1087);
    return _p;
L2:
    ;
}


int _10NewDoubleSym(int _d)
{
    int _p;
    int _tp;
    int _prev;
    int _search_count;
    int _1111 = 0;
    int _1110 = 0;
    int _1102 = 0;
    int _0, _1, _2, _3;
    

    //     tp = literal_init
    _tp = _10literal_init;

    //     prev = 0
    _prev = 0;

    //     search_count = 0
    _search_count = 0;

    //     while tp != 0 do
L1:
    if (_tp == 0)
        goto L2;

    // 	search_count += 1
    _search_count = _search_count + 1;

    // 	if search_count > SEARCH_LIMIT then  -- avoid n-squared algorithm
    if (binary_op_a(LESSEQ, _search_count, _10SEARCH_LIMIT))
        goto L3;

    // 	    exit
    goto L2;
L3:

    // 	if equal(d, SymTab[tp][S_OBJ]) then
    DeRef(_1102);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1102 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_1102);
    _0 = _1102;
    _2 = (int)SEQ_PTR(_1102);
    _1102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1102);
    DeRefDS(_0);
    _0 = _1102;
    if (_d == _1102)
        _1102 = 1;
    else if (IS_ATOM_INT(_d) && IS_ATOM_INT(_1102))
        _1102 = 0;
    else
        _1102 = (compare(_d, _1102) == 0);
    DeRef(_0);
    if (_1102 == 0)
        goto L4;

    // 	    if tp != literal_init then
    if (_tp == _10literal_init)
        goto L5;

    // 		SymTab[prev][S_NEXT] = SymTab[tp][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev + ((s1_ptr)_2)->base);
    DeRef(_1111);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1111 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_1111);
    _0 = _1111;
    _2 = (int)SEQ_PTR(_1111);
    _1111 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1111);
    DeRefDS(_0);
    Ref(_1111);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1111;
    DeRef(_1);

    // 		SymTab[tp][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_tp + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _10literal_init;
    DeRef(_1);

    // 		literal_init = tp
    _10literal_init = _tp;
L5:

    // 	    return tp
    DeRef(_d);
    DeRef(_1111);
    DeRef(_1110);
    DeRef(_1102);
    return _tp;
L4:

    // 	prev = tp
    _prev = _tp;

    // 	tp = SymTab[tp][S_NEXT]
    DeRef(_1110);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1110 = (int)*(((s1_ptr)_2)->base + _tp);
    RefDS(_1110);
    _2 = (int)SEQ_PTR(_1110);
    _tp = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_tp))
        _tp = (long)DBL_PTR(_tp)->dbl;

    //     end while
    goto L1;
L2:

    //     p = tmp_alloc()
    _p = _10tmp_alloc();

    //     SymTab[p][S_MODE] = M_CONSTANT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    //     SymTab[p][S_OBJ] = d
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    Ref(_d);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _d;
    DeRef(_1);

    //     if TRANSLATE then

    // 	SymTab[p][S_MODE] = M_TEMP  -- override CONSTANT for compile
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[p][S_GTYPE] = TYPE_DOUBLE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	c_printf("int _%d;\n", SymTab[p][S_TEMP_NAME])
    DeRef(_1110);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1110 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1110);
    _0 = _1110;
    _2 = (int)SEQ_PTR(_1110);
    _1110 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_1110);
    DeRefDS(_0);
    RefDS(_1073);
    Ref(_1110);
    _9c_printf(_1073, _1110);

    // 	c_hprintf("extern int _%d;\n", SymTab[p][S_TEMP_NAME])
    DeRef(_1110);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1110 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1110);
    _0 = _1110;
    _2 = (int)SEQ_PTR(_1110);
    _1110 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_1110);
    DeRefDS(_0);
    RefDS(_1076);
    Ref(_1110);
    _9c_hprintf(_1076, _1110);
L6:

    //     SymTab[p][S_NEXT] = literal_init
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _10literal_init;
    DeRef(_1);

    //     literal_init = p
    _10literal_init = _p;

    //     return p
    DeRef(_d);
    DeRef(_1111);
    DeRef(_1110);
    DeRef(_1102);
    return _p;
    ;
}


int _10NewTempSym()
{
    int _p;
    int _q;
    int _1136 = 0;
    int _1148 = 0;
    int _1132 = 0;
    int _0, _1, _2, _3;
    

    //     p = SymTab[CurrentSub][S_TEMPS]
    _2 = (int)SEQ_PTR(_4SymTab);
    _1132 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1132);
    _2 = (int)SEQ_PTR(_1132);
    _p = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     while p != 0 and SymTab[p][S_SCOPE] != FREE do
L1:
    DeRef(_1132);
    _1132 = (_p != 0);
    if (_1132 == 0) {
        goto L2;
    }
    DeRef(_1136);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1136 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1136);
    _0 = _1136;
    _2 = (int)SEQ_PTR(_1136);
    _1136 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1136);
    DeRefDS(_0);
    _0 = _1136;
    if (IS_ATOM_INT(_1136)) {
        _1136 = (_1136 != 0);
    }
    else {
        _1136 = binary_op(NOTEQ, _1136, 0);
    }
    DeRef(_0);
L3:
    if (_1136 <= 0) {
        if (_1136 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_1136) && DBL_PTR(_1136)->dbl == 0.0)
                goto L2;
        }
    }

    // 	p = SymTab[p][S_NEXT]
    DeRef(_1136);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1136 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1136);
    _2 = (int)SEQ_PTR(_1136);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     end while
    goto L1;
L2:

    //     if p = 0 then
    if (_p != 0)
        goto L4;

    // 	temps_allocated += 1
    _10temps_allocated = _10temps_allocated + 1;

    // 	p = tmp_alloc()
    _p = _10tmp_alloc();

    // 	SymTab[p][S_MODE] = M_TEMP
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[p][S_NEXT] = SymTab[CurrentSub][S_TEMPS]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_1148);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1148 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1148);
    _0 = _1148;
    _2 = (int)SEQ_PTR(_1148);
    _1148 = (int)*(((s1_ptr)_2)->base + 18);
    Ref(_1148);
    DeRefDS(_0);
    Ref(_1148);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1148;
    DeRef(_1);

    // 	SymTab[CurrentSub][S_TEMPS] = p
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = _p;
    DeRef(_1);
    goto L5;
L4:

    //     elsif TRANSLATE then

    // 	SymTab[p][S_SCOPE] = DELETED
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	q = tmp_alloc()
    _q = _10tmp_alloc();

    // 	SymTab[q][S_MODE] = M_TEMP
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_q + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[q][S_TEMP_NAME] = SymTab[p][S_TEMP_NAME]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_q + ((s1_ptr)_2)->base);
    DeRef(_1132);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1132 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1132);
    _0 = _1132;
    _2 = (int)SEQ_PTR(_1132);
    _1132 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_1132);
    DeRefDS(_0);
    Ref(_1132);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 31);
    _1 = *(int *)_2;
    *(int *)_2 = _1132;
    DeRef(_1);

    // 	SymTab[q][S_NEXT] = SymTab[CurrentSub][S_TEMPS]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_q + ((s1_ptr)_2)->base);
    DeRef(_1136);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1136 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1136);
    _0 = _1136;
    _2 = (int)SEQ_PTR(_1136);
    _1136 = (int)*(((s1_ptr)_2)->base + 18);
    Ref(_1136);
    DeRefDS(_0);
    Ref(_1136);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _1136;
    DeRef(_1);

    // 	SymTab[CurrentSub][S_TEMPS] = q
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = _q;
    DeRef(_1);

    // 	p = q
    _p = _q;
L6:
L5:

    //     if TRANSLATE then

    // 	SymTab[p][S_GTYPE] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);

    // 	SymTab[p][S_SEQ_ELEM] = TYPE_OBJECT
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);
L7:

    //     SymTab[p][S_OBJ] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    //     SymTab[p][S_USAGE] = T_UNKNOWN
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);

    //     SymTab[p][S_SCOPE] = IN_USE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     return p
    DeRef(_1136);
    DeRef(_1148);
    DeRef(_1132);
    return _p;
    ;
}


int _10InitSymTab()
{
    int _hashval;
    int _len;
    int _s;
    int _st_index;
    int _kname = 0;
    int _1199 = 0;
    int _1178 = 0;
    int _1184 = 0;
    int _1177;
    int _0, _1, _2, _3;
    

    //     for k = 1 to length(keylist) do 
    _1177 = SEQ_PTR(_8keylist)->length;
    { int _k;
        _k = 1;
L1:
        if (_k > _1177)
            goto L2;

        // 	kname = keylist[k][K_NAME]
        DeRef(_1178);
        _2 = (int)SEQ_PTR(_8keylist);
        _1178 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1178);
        DeRef(_kname);
        _2 = (int)SEQ_PTR(_1178);
        _kname = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_kname);

        // 	len = length(kname)
        _len = SEQ_PTR(_kname)->length;

        // 	hashval = hashfn(kname)
        RefDS(_kname);
        _hashval = _10hashfn(_kname);

        // 	st_index = NewEntry(kname,
        DeRefDS(_1178);
        _2 = (int)SEQ_PTR(_8keylist);
        _1178 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1178);
        _0 = _1178;
        _2 = (int)SEQ_PTR(_1178);
        _1178 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_1178);
        DeRefDS(_0);
        DeRef(_1184);
        _2 = (int)SEQ_PTR(_8keylist);
        _1184 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1184);
        _0 = _1184;
        _2 = (int)SEQ_PTR(_1184);
        _1184 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1184);
        DeRefDS(_0);
        RefDS(_kname);
        Ref(_1178);
        Ref(_1184);
        _st_index = _10NewEntry(_kname, 0, _1178, _1184, _hashval, 0, 0);

        // 	if find(keylist[k][K_TOKEN], {PROC, FUNC, TYPE}) then
        DeRef(_1184);
        _2 = (int)SEQ_PTR(_8keylist);
        _1184 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1184);
        _0 = _1184;
        _2 = (int)SEQ_PTR(_1184);
        _1184 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1184);
        DeRefDS(_0);
        _0 = _1178;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 27;
        *((int *)(_2+8)) = 501;
        *((int *)(_2+12)) = 504;
        _1178 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _1178;
        _1178 = find(_1184, _1178);
        DeRefDSi(_0);
        if (_1178 == 0)
            goto L3;

        // 	    SymTab[st_index] = SymTab[st_index] & 
        _2 = (int)SEQ_PTR(_4SymTab);
        _1178 = (int)*(((s1_ptr)_2)->base + _st_index);
        RefDS(_1178);
        DeRef(_1184);
        _2 = (int)SEQ_PTR(_4SymTab);
        _1184 = (int)*(((s1_ptr)_2)->base + _st_index);
        RefDS(_1184);
        _0 = _1184;
        _1184 = SEQ_PTR(_1184)->length;
        DeRefDS(_0);
        _1184 = 49 - _1184;
        _1184 = Repeat(0, _1184);
        Concat((object_ptr)&_1184, _1178, (s1_ptr)_1184);
        RefDS(_1184);
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _st_index);
        _1 = *(int *)_2;
        *(int *)_2 = _1184;
        DeRefDS(_1);

        // 	    SymTab[st_index][S_NUM_ARGS] = keylist[k][K_NUM_ARGS]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        DeRef(_1199);
        _2 = (int)SEQ_PTR(_8keylist);
        _1199 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1199);
        _0 = _1199;
        _2 = (int)SEQ_PTR(_1199);
        _1199 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_1199);
        DeRefDS(_0);
        Ref(_1199);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 20);
        _1 = *(int *)_2;
        *(int *)_2 = _1199;
        DeRef(_1);

        // 	    SymTab[st_index][S_OPCODE] = keylist[k][K_OPCODE]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        DeRefDS(_1184);
        _2 = (int)SEQ_PTR(_8keylist);
        _1184 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1184);
        _0 = _1184;
        _2 = (int)SEQ_PTR(_1184);
        _1184 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_1184);
        DeRefDS(_0);
        Ref(_1184);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 19);
        _1 = *(int *)_2;
        *(int *)_2 = _1184;
        DeRef(_1);

        // 	    SymTab[st_index][S_EFFECT] = keylist[k][K_EFFECT]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        DeRef(_1199);
        _2 = (int)SEQ_PTR(_8keylist);
        _1199 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1199);
        _0 = _1199;
        _2 = (int)SEQ_PTR(_1199);
        _1199 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_1199);
        DeRefDS(_0);
        Ref(_1199);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 21);
        _1 = *(int *)_2;
        *(int *)_2 = _1199;
        DeRef(_1);

        // 	    SymTab[st_index][S_REFLIST] = {}
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_st_index + ((s1_ptr)_2)->base);
        RefDS(_39);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 22);
        _1 = *(int *)_2;
        *(int *)_2 = _39;
        DeRef(_1);
L3:

        // 	if keylist[k][K_TOKEN] = PROC then
        DeRef(_1178);
        _2 = (int)SEQ_PTR(_8keylist);
        _1178 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1178);
        _0 = _1178;
        _2 = (int)SEQ_PTR(_1178);
        _1178 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1178);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _1178, 27))
            goto L4;

        // 	    if equal(kname, "_toplevel_") then
        DeRef(_1178);
        if (_kname == _862)
            _1178 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_862))
            _1178 = 0;
        else
            _1178 = (compare(_kname, _862) == 0);
        if (_1178 == 0)
            goto L5;

        // 		TopLevelSub = st_index
        _4TopLevelSub = _st_index;
L6:
        goto L5;
L4:

        // 	elsif keylist[k][K_TOKEN] = TYPE then
        DeRef(_1178);
        _2 = (int)SEQ_PTR(_8keylist);
        _1178 = (int)*(((s1_ptr)_2)->base + _k);
        RefDS(_1178);
        _0 = _1178;
        _2 = (int)SEQ_PTR(_1178);
        _1178 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_1178);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _1178, 504))
            goto L7;

        // 	    if equal(kname, "object") then
        DeRef(_1178);
        if (_kname == _718)
            _1178 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_718))
            _1178 = 0;
        else
            _1178 = (compare(_kname, _718) == 0);
        if (_1178 == 0)
            goto L8;

        // 		object_type = st_index
        _10object_type = _st_index;
        goto L9;
L8:

        // 	    elsif equal(kname, "atom") then
        DeRef(_1178);
        if (_kname == _742)
            _1178 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_742))
            _1178 = 0;
        else
            _1178 = (compare(_kname, _742) == 0);
        if (_1178 == 0)
            goto LA;

        // 		atom_type = st_index
        _10atom_type = _st_index;
        goto L9;
LA:

        // 	    elsif equal(kname, "integer") then
        DeRef(_1178);
        if (_kname == _712)
            _1178 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_712))
            _1178 = 0;
        else
            _1178 = (compare(_kname, _712) == 0);
        if (_1178 == 0)
            goto LB;

        // 		integer_type = st_index
        _10integer_type = _st_index;
        goto L9;
LB:

        // 	    elsif equal(kname, "sequence") then
        DeRef(_1178);
        if (_kname == _714)
            _1178 = 1;
        else if (IS_ATOM_INT(_kname) && IS_ATOM_INT(_714))
            _1178 = 0;
        else
            _1178 = (compare(_kname, _714) == 0);
        if (_1178 == 0)
            goto LC;

        // 		sequence_type = st_index
        _10sequence_type = _st_index;
LC:
L9:
L7:
L5:

        // 	if buckets[hashval] = 0 then
        DeRef(_1178);
        _2 = (int)SEQ_PTR(_10buckets);
        _1178 = (int)*(((s1_ptr)_2)->base + _hashval);
        Ref(_1178);
        if (binary_op_a(NOTEQ, _1178, 0))
            goto LD;

        // 	    buckets[hashval] = st_index
        _2 = (int)SEQ_PTR(_10buckets);
        _2 = (int)(((s1_ptr)_2)->base + _hashval);
        _1 = *(int *)_2;
        *(int *)_2 = _st_index;
        DeRef(_1);
        goto LE;
LD:

        // 	    s = buckets[hashval]
        _2 = (int)SEQ_PTR(_10buckets);
        _s = (int)*(((s1_ptr)_2)->base + _hashval);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    while SymTab[s][S_SAMEHASH] != 0 do 
LF:
        DeRef(_1178);
        _2 = (int)SEQ_PTR(_4SymTab);
        _1178 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_1178);
        _0 = _1178;
        _2 = (int)SEQ_PTR(_1178);
        _1178 = (int)*(((s1_ptr)_2)->base + 8);
        Ref(_1178);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _1178, 0))
            goto L10;

        // 		s = SymTab[s][S_SAMEHASH]
        DeRef(_1178);
        _2 = (int)SEQ_PTR(_4SymTab);
        _1178 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_1178);
        _2 = (int)SEQ_PTR(_1178);
        _s = (int)*(((s1_ptr)_2)->base + 8);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    end while
        goto LF;
L10:

        // 	    SymTab[s][S_SAMEHASH] = st_index
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_s + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 8);
        _1 = *(int *)_2;
        *(int *)_2 = _st_index;
        DeRef(_1);
LE:

        //     end for
        _k = _k + 1;
        goto L1;
L2:
        ;
    }

    //     file_start_sym = length(SymTab)
    _4file_start_sym = SEQ_PTR(_4SymTab)->length;

    // end procedure
    DeRef(_kname);
    DeRef(_1199);
    DeRef(_1178);
    DeRef(_1184);
    return 0;
    ;
}


int _10add_ref(int _tok)
{
    int _s;
    int _1236 = 0;
    int _1233;
    int _1242 = 0;
    int _0, _1, _2, _3;
    

    //     s = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     if s != CurrentSub and -- ignore self-ref's
    _1233 = (_s != _4CurrentSub);
    if (_1233 == 0) {
        goto L1;
    }
    _2 = (int)SEQ_PTR(_4SymTab);
    _1236 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1236);
    _0 = _1236;
    _2 = (int)SEQ_PTR(_1236);
    _1236 = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_1236);
    DeRefDS(_0);
    _0 = _1236;
    _1236 = find(_s, _1236);
    DeRef(_0);
    _1236 = (_1236 == 0);
L2:
    if (_1236 == 0)
        goto L1;

    // 	SymTab[s][S_NREFS] += 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_1242);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1242 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_1242);
    _0 = _1242;
    if (IS_ATOM_INT(_1242)) {
        _1242 = _1242 + 1;
        if (_1242 > MAXINT)
            _1242 = NewDouble((double)_1242);
    }
    else
        _1242 = binary_op(PLUS, 1, _1242);
    DeRef(_0);
    Ref(_1242);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = _1242;
    DeRef(_1);

    // 	SymTab[CurrentSub][S_REFLIST] &= s
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    DeRef(_1236);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1236 = (int)*(((s1_ptr)_2)->base + 22);
    Ref(_1236);
    if (IS_SEQUENCE(_1236) && IS_ATOM(_s)) {
        Append(&_1236, _1236, _s);
    }
    else if (IS_ATOM(_1236) && IS_SEQUENCE(_s)) {
    }
    else {
        Concat((object_ptr)&_1236, _1236, (s1_ptr)_s);
    }
    RefDS(_1236);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 22);
    _1 = *(int *)_2;
    *(int *)_2 = _1236;
    DeRef(_1);
L1:

    // end procedure
    DeRefDS(_tok);
    DeRef(_1236);
    DeRef(_1242);
    return 0;
    ;
}


int _10MarkTargets(int _s, int _attribute)
{
    int _p;
    int _sname = 0;
    int _string = 0;
    int _colon;
    int _h;
    int _1252 = 0;
    int _1286 = 0;
    int _1248 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }
    if (!IS_ATOM_INT(_attribute)) {
        _1 = (long)(DBL_PTR(_attribute)->dbl);
        DeRefDS(_attribute);
        _attribute = _1;
    }

    //     if (SymTab[s][S_MODE] = M_TEMP or
    _2 = (int)SEQ_PTR(_4SymTab);
    _1248 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1248);
    _0 = _1248;
    _2 = (int)SEQ_PTR(_1248);
    _1248 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1248);
    DeRefDS(_0);
    _0 = _1248;
    if (IS_ATOM_INT(_1248)) {
        _1248 = (_1248 == 3);
    }
    else {
        _1248 = binary_op(EQUALS, _1248, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1248)) {
        if (_1248 != 0) {
            DeRef(_1248);
            _1248 = 1;
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_1248)->dbl != 0.0) {
            DeRef(_1248);
            _1248 = 1;
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_4SymTab);
    _1252 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1252);
    _0 = _1252;
    _2 = (int)SEQ_PTR(_1252);
    _1252 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1252);
    DeRefDS(_0);
    _0 = _1252;
    if (IS_ATOM_INT(_1252)) {
        _1252 = (_1252 == 2);
    }
    else {
        _1252 = binary_op(EQUALS, _1252, 2);
    }
    DeRef(_0);
    DeRef(_1248);
    if (IS_ATOM_INT(_1252))
        _1248 = (_1252 != 0);
    else
        _1248 = DBL_PTR(_1252)->dbl != 0.0;
L1:
    if (_1248 == 0) {
        goto L2;
    }
    DeRef(_1248);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1248 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1248);
    _0 = _1248;
    _2 = (int)SEQ_PTR(_1248);
    _1248 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1248);
    DeRefDS(_0);
    _0 = _1248;
    _1248 = IS_SEQUENCE(_1248);
    DeRef(_0);
L3:
    if (_1248 == 0)
        goto L2;

    // 	string = SymTab[s][S_OBJ] 
    DeRef(_1248);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1248 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1248);
    DeRef(_string);
    _2 = (int)SEQ_PTR(_1248);
    _string = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_string);

    // 	colon = find(':', string)
    _colon = find(58, _string);

    // 	if colon = 0 then
    if (_colon != 0)
        goto L4;

    // 	    sname = string
    RefDS(_string);
    DeRef(_sname);
    _sname = _string;
    goto L5;
L4:

    // 	    sname = string[colon+1..$]  -- ignore namespace part
    DeRef(_1248);
    _1248 = _colon + 1;
    DeRef(_1252);
    _1252 = SEQ_PTR(_string)->length;
    rhs_slice_target = (object_ptr)&_sname;
    RHS_Slice((s1_ptr)_string, _1248, _1252);

    // 	    while length(sname) and sname[1] = ' ' or sname[1] = '\t' do
L6:
    DeRef(_1252);
    _1252 = SEQ_PTR(_sname)->length;
    if (_1252 == 0) {
        _1252 = 0;
        goto L7;
    }
    DeRef(_1248);
    _2 = (int)SEQ_PTR(_sname);
    _1248 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1248);
    _0 = _1248;
    if (IS_ATOM_INT(_1248)) {
        _1248 = (_1248 == 32);
    }
    else {
        _1248 = binary_op(EQUALS, _1248, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1248))
        _1252 = (_1248 != 0);
    else
        _1252 = DBL_PTR(_1248)->dbl != 0.0;
L7:
    if (_1252 != 0) {
        goto L8;
    }
    DeRef(_1252);
    _2 = (int)SEQ_PTR(_sname);
    _1252 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1252);
    _0 = _1252;
    if (IS_ATOM_INT(_1252)) {
        _1252 = (_1252 == 9);
    }
    else {
        _1252 = binary_op(EQUALS, _1252, 9);
    }
    DeRef(_0);
L9:
    if (_1252 <= 0) {
        if (_1252 == 0) {
            goto LA;
        }
        else {
            if (!IS_ATOM_INT(_1252) && DBL_PTR(_1252)->dbl == 0.0)
                goto LA;
        }
    }
L8:

    // 		sname = sname[2..$]
    DeRef(_1252);
    _1252 = SEQ_PTR(_sname)->length;
    rhs_slice_target = (object_ptr)&_sname;
    RHS_Slice((s1_ptr)_sname, 2, _1252);

    // 	    end while   
    goto L6;
LA:
L5:

    // 	if length(sname) = 0 then
    DeRef(_1252);
    _1252 = SEQ_PTR(_sname)->length;
    if (_1252 != 0)
        goto LB;

    // 	    return
    DeRefDS(_sname);
    DeRef(_string);
    DeRef(_1286);
    DeRef(_1248);
    return 0;
LB:

    // 	h = buckets[hashfn(sname)]
    RefDS(_sname);
    _0 = _1252;
    _1252 = _10hashfn(_sname);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_10buckets);
    _h = (int)*(((s1_ptr)_2)->base + _1252);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	while h do
LC:
    if (_h == 0)
        goto LD;

    // 	    if equal(sname, SymTab[h][S_NAME]) then
    DeRef(_1252);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1252 = (int)*(((s1_ptr)_2)->base + _h);
    RefDS(_1252);
    _0 = _1252;
    _2 = (int)SEQ_PTR(_1252);
    _1252 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1252);
    DeRefDS(_0);
    _0 = _1252;
    if (_sname == _1252)
        _1252 = 1;
    else if (IS_ATOM_INT(_sname) && IS_ATOM_INT(_1252))
        _1252 = 0;
    else
        _1252 = (compare(_sname, _1252) == 0);
    DeRef(_0);
    if (_1252 == 0)
        goto LE;

    // 		if attribute = S_NREFS then
    if (_attribute != 11)
        goto LF;

    // 		    if BIND then
    goto L10;
LF:

    // 		    SymTab[h][attribute] += 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_h + ((s1_ptr)_2)->base);
    DeRef(_1286);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1286 = (int)*(((s1_ptr)_2)->base + _attribute);
    Ref(_1286);
    _0 = _1286;
    if (IS_ATOM_INT(_1286)) {
        _1286 = _1286 + 1;
        if (_1286 > MAXINT)
            _1286 = NewDouble((double)_1286);
    }
    else
        _1286 = binary_op(PLUS, 1, _1286);
    DeRef(_0);
    Ref(_1286);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _attribute);
    _1 = *(int *)_2;
    *(int *)_2 = _1286;
    DeRef(_1);
L10:
LE:

    // 	    h = SymTab[h][S_SAMEHASH]
    DeRef(_1286);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1286 = (int)*(((s1_ptr)_2)->base + _h);
    RefDS(_1286);
    _2 = (int)SEQ_PTR(_1286);
    _h = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	end while           
    goto LC;
L11:
    goto LD;
L2:

    // 	p = SymTab[TopLevelSub][S_NEXT]
    DeRef(_1286);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1286 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_1286);
    _2 = (int)SEQ_PTR(_1286);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	while p != 0 do
L12:
    if (_p == 0)
        goto L13;

    // 	    if SymTab[p][S_FILE_NO] = current_file_no or
    DeRef(_1286);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1286 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1286);
    _0 = _1286;
    _2 = (int)SEQ_PTR(_1286);
    _1286 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1286);
    DeRefDS(_0);
    _0 = _1286;
    if (IS_ATOM_INT(_1286)) {
        _1286 = (_1286 == _4current_file_no);
    }
    else {
        _1286 = binary_op(EQUALS, _1286, _4current_file_no);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1286)) {
        if (_1286 != 0) {
            goto L14;
        }
    }
    else {
        if (DBL_PTR(_1286)->dbl != 0.0) {
            goto L14;
        }
    }
    DeRef(_1248);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1248 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1248);
    _0 = _1248;
    _2 = (int)SEQ_PTR(_1248);
    _1248 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1248);
    DeRefDS(_0);
    _0 = _1248;
    if (IS_ATOM_INT(_1248)) {
        _1248 = (_1248 == 6);
    }
    else {
        _1248 = binary_op(EQUALS, _1248, 6);
    }
    DeRef(_0);
L15:
    if (_1248 == 0) {
        goto L16;
    }
    else {
        if (!IS_ATOM_INT(_1248) && DBL_PTR(_1248)->dbl == 0.0)
            goto L16;
    }
L14:

    // 		SymTab[p][attribute] += 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_1252);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _1252 = (int)*(((s1_ptr)_2)->base + _attribute);
    Ref(_1252);
    _0 = _1252;
    if (IS_ATOM_INT(_1252)) {
        _1252 = _1252 + 1;
        if (_1252 > MAXINT)
            _1252 = NewDouble((double)_1252);
    }
    else
        _1252 = binary_op(PLUS, 1, _1252);
    DeRef(_0);
    Ref(_1252);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _attribute);
    _1 = *(int *)_2;
    *(int *)_2 = _1252;
    DeRef(_1);
L16:

    // 	    p = SymTab[p][S_NEXT]
    DeRef(_1252);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1252 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1252);
    _2 = (int)SEQ_PTR(_1252);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	end while
    goto L12;
L13:
LD:

    // end procedure
    DeRef(_sname);
    DeRef(_string);
    DeRef(_1252);
    DeRef(_1286);
    DeRef(_1248);
    return 0;
    ;
}


