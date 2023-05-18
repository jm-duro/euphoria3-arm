// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _4boolean(int _x)
{
    int _263;
    int _262;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     return x = TRUE or x = FALSE
    _262 = (_x == 1);
    _263 = (_x == 0);
    _263 = (_262 != 0 || _263 != 0);
    return _263;
    ;
}


int _4symtab_entry(int _x)
{
    int _324;
    int _322;
    int _0, _1, _2;
    

    //     return length(x) = SIZEOF_ROUTINE_ENTRY or 
    _322 = SEQ_PTR(_x)->length;
    _322 = (_322 == 25);
    _324 = SEQ_PTR(_x)->length;
    _324 = (_324 == 14);
    _324 = (_322 != 0 || _324 != 0);
    DeRefDS(_x);
    return _324;
    ;
}


int _4symtab_index(int _x)
{
    int _327 = 0;
    int _330 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     if x = 0 then
    if (_x != 0)
        goto L1;

    // 	return TRUE -- NULL value
    return 1;
L1:

    //     if x < 0 or x > length(SymTab) then
    DeRef(_327);
    _327 = (_x < 0);
    if (_327 != 0) {
        goto L2;
    }
    DeRef(_330);
    _330 = SEQ_PTR(_4SymTab)->length;
    _330 = (_x > _330);
L3:
    if (_330 == 0)
        goto L4;
L2:

    // 	return FALSE
    DeRef(_327);
    DeRef(_330);
    return 0;
L4:

    //     return find(length(SymTab[x]), {SIZEOF_VAR_ENTRY, SIZEOF_ROUTINE_ENTRY,
    DeRef(_330);
    _2 = (int)SEQ_PTR(_4SymTab);
    _330 = (int)*(((s1_ptr)_2)->base + _x);
    RefDS(_330);
    _0 = _330;
    _330 = SEQ_PTR(_330)->length;
    DeRefDS(_0);
    _0 = _327;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 14;
    *((int *)(_2+8)) = 25;
    *((int *)(_2+12)) = 5;
    _327 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _327;
    _327 = find(_330, _327);
    DeRefDSi(_0);
    return _327;
    ;
}


int _4temp_index(int _x)
{
    int _337;
    int _336;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     return x >= 0 and x <= length(SymTab)
    _336 = (_x >= 0);
    _337 = SEQ_PTR(_4SymTab)->length;
    _337 = (_x <= _337);
    _337 = (_336 != 0 && _337 != 0);
    return _337;
    ;
}


int _4token(int _t)
{
    int _340 = 0;
    int _342 = 0;
    int _0, _1, _2;
    

    //     return length(t) = 2 and integer(t[T_ID]) and symtab_index(t[T_SYM])
    _340 = SEQ_PTR(_t)->length;
    _340 = (_340 == 2);
    _2 = (int)SEQ_PTR(_t);
    _342 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_342);
    _0 = _342;
    if (IS_ATOM_INT(_342))
        _342 = 1;
    else if (IS_ATOM_DBL(_342))
        _342 = IS_ATOM_INT(DoubleToInt(_342));
    else
        _342 = 0;
    DeRef(_0);
    _342 = (_340 != 0 && _342 != 0);
    _2 = (int)SEQ_PTR(_t);
    _340 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_340);
    Ref(_340);
    _0 = _340;
    _340 = _4symtab_index(_340);
    DeRef(_0);
    _340 = (_342 != 0 && _340 != 0);
    DeRefDS(_t);
    return _340;
    ;
}


int _4file(int _f)
{
    int _350;
    int _348;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_f)) {
        _1 = (long)(DBL_PTR(_f)->dbl);
        DeRefDS(_f);
        _f = _1;
    }

    //     return f >= -1 and f < 100 -- rough limit
    _348 = (_f >= -1);
    _350 = (_f < 100);
    _350 = (_348 != 0 && _350 != 0);
    return _350;
    ;
}


