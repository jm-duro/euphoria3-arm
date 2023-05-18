// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _10keyfind(int _word, int _file_no)
{
    int _hashval;
    int _scope;
    int _defined;
    int _st_ptr;
    int _tok = 0;
    int _gtok = 0;
    int _1334 = 0;
    int _1306 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file_no)) {
        _1 = (long)(DBL_PTR(_file_no)->dbl);
        DeRefDS(_file_no);
        _file_no = _1;
    }

    //     dup_globals = {}
    RefDS(_39);
    DeRefi(_10dup_globals);
    _10dup_globals = _39;

    //     hashval = hashfn(word)
    RefDS(_word);
    _hashval = _10hashfn(_word);

    //     st_ptr = buckets[hashval] 
    _2 = (int)SEQ_PTR(_10buckets);
    _st_ptr = (int)*(((s1_ptr)_2)->base + _hashval);
    if (!IS_ATOM_INT(_st_ptr))
        _st_ptr = (long)DBL_PTR(_st_ptr)->dbl;

    //     while st_ptr do
L1:
    if (_st_ptr == 0)
        goto L2;

    // 	if equal(word, SymTab[st_ptr][S_NAME]) then
    DeRef(_1306);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1306 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    RefDS(_1306);
    _0 = _1306;
    _2 = (int)SEQ_PTR(_1306);
    _1306 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1306);
    DeRefDS(_0);
    _0 = _1306;
    if (_word == _1306)
        _1306 = 1;
    else if (IS_ATOM_INT(_word) && IS_ATOM_INT(_1306))
        _1306 = 0;
    else
        _1306 = (compare(_word, _1306) == 0);
    DeRef(_0);
    if (_1306 == 0)
        goto L3;

    // 	    tok = {SymTab[st_ptr][S_TOKEN], st_ptr}
    _2 = (int)SEQ_PTR(_4SymTab);
    _1306 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    RefDS(_1306);
    _0 = _1306;
    _2 = (int)SEQ_PTR(_1306);
    _1306 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_1306);
    DeRefDS(_0);
    DeRef(_tok);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _1306;
    Ref(_1306);
    ((int *)_2)[2] = _st_ptr;
    _tok = MAKE_SEQ(_1);

    // 	    if file_no = -1 then
    if (_file_no != -1)
        goto L4;

    // 		scope = SymTab[st_ptr][S_SCOPE]
    DeRef(_1306);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1306 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    RefDS(_1306);
    _2 = (int)SEQ_PTR(_1306);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    // 		if scope = SC_GLOBAL then
    if (_scope != 6)
        goto L5;

    // 		    if current_file_no = SymTab[st_ptr][S_FILE_NO] then
    DeRefDS(_1306);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1306 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    RefDS(_1306);
    _0 = _1306;
    _2 = (int)SEQ_PTR(_1306);
    _1306 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1306);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4current_file_no, _1306))
        goto L6;

    // 			if BIND then

    // 			return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1334);
    DeRef(_1306);
    return _tok;
L6:

    // 		    gtok = tok
    RefDS(_tok);
    DeRef(_gtok);
    _gtok = _tok;

    // 		    dup_globals &= st_ptr               
    Append(&_10dup_globals, _10dup_globals, _st_ptr);
    goto L7;
L5:

    // 		elsif scope = SC_LOCAL then 
    if (_scope != 5)
        goto L8;

    // 		    if current_file_no = SymTab[st_ptr][S_FILE_NO] then
    DeRef(_1306);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1306 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    RefDS(_1306);
    _0 = _1306;
    _2 = (int)SEQ_PTR(_1306);
    _1306 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1306);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4current_file_no, _1306))
        goto L7;

    // 			if BIND then

    // 			return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1334);
    DeRef(_1306);
    return _tok;
L9:
    goto L7;
L8:

    // 		elsif scope = SC_PREDEF then
    if (_scope != 7)
        goto LA;

    // 		    if length(dup_globals) = 0 then
    DeRef(_1306);
    _1306 = SEQ_PTR(_10dup_globals)->length;
    if (_1306 != 0)
        goto L7;

    // 			if BIND then

    // 			return tok
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1334);
    return _tok;
LB:
    goto L7;
LA:

    // 		    if BIND then

    // 		    return tok -- keyword, private
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1334);
    DeRef(_1306);
    return _tok;
LC:
    goto L7;
L4:

    // 		if file_no = SymTab[tok[T_SYM]][S_FILE_NO] and
    DeRef(_1306);
    _2 = (int)SEQ_PTR(_tok);
    _1306 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1306);
    _0 = _1306;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_1306))
        _1306 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1306)->dbl));
    else
        _1306 = (int)*(((s1_ptr)_2)->base + _1306);
    RefDS(_1306);
    DeRef(_0);
    _0 = _1306;
    _2 = (int)SEQ_PTR(_1306);
    _1306 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1306);
    DeRefDS(_0);
    _0 = _1306;
    if (IS_ATOM_INT(_1306)) {
        _1306 = (_file_no == _1306);
    }
    else {
        _1306 = binary_op(EQUALS, _file_no, _1306);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1306)) {
        if (_1306 == 0) {
            goto LD;
        }
    }
    else {
        if (DBL_PTR(_1306)->dbl == 0.0) {
            goto LD;
        }
    }
    DeRef(_1334);
    _2 = (int)SEQ_PTR(_tok);
    _1334 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1334);
    _0 = _1334;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_1334))
        _1334 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1334)->dbl));
    else
        _1334 = (int)*(((s1_ptr)_2)->base + _1334);
    RefDS(_1334);
    DeRef(_0);
    _0 = _1334;
    _2 = (int)SEQ_PTR(_1334);
    _1334 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1334);
    DeRefDS(_0);
    _0 = _1334;
    if (IS_ATOM_INT(_1334)) {
        _1334 = (_1334 == 6);
    }
    else {
        _1334 = binary_op(EQUALS, _1334, 6);
    }
    DeRef(_0);
LE:
    if (_1334 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_1334) && DBL_PTR(_1334)->dbl == 0.0)
            goto LD;
    }

    // 		    if BIND then

    // 		    return tok 
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1334);
    DeRef(_1306);
    return _tok;
LD:
L7:
L3:

    // 	st_ptr = SymTab[st_ptr][S_SAMEHASH]
    DeRef(_1334);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1334 = (int)*(((s1_ptr)_2)->base + _st_ptr);
    RefDS(_1334);
    _2 = (int)SEQ_PTR(_1334);
    _st_ptr = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_st_ptr))
        _st_ptr = (long)DBL_PTR(_st_ptr)->dbl;

    //     end while
    goto L1;
L2:

    //     if length(dup_globals) = 1 then
    DeRef(_1334);
    _1334 = SEQ_PTR(_10dup_globals)->length;
    if (_1334 != 1)
        goto LF;

    // 	if BIND then

    // 	return gtok
    DeRefDS(_word);
    DeRef(_tok);
    DeRef(_1306);
    return _gtok;
LF:

    //     if length(dup_globals) = 0 then
    DeRef(_1334);
    _1334 = SEQ_PTR(_10dup_globals)->length;
    if (_1334 != 0)
        goto L10;

    // 	defined = SC_UNDEFINED
    _defined = 9;
    goto L11;
L10:

    // 	defined = SC_MULTIPLY_DEFINED
    _defined = 10;
L11:

    //     tok = {VARIABLE, NewEntry(word, 0, defined, 
    DeRef(_1334);
    _2 = (int)SEQ_PTR(_10buckets);
    _1334 = (int)*(((s1_ptr)_2)->base + _hashval);
    Ref(_1334);
    RefDS(_word);
    Ref(_1334);
    _0 = _1334;
    _1334 = _10NewEntry(_word, 0, _defined, -100, _hashval, _1334, 0);
    DeRef(_0);
    DeRef(_tok);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -100;
    ((int *)_2)[2] = _1334;
    _tok = MAKE_SEQ(_1);

    //     buckets[hashval] = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _1334 = (int)*(((s1_ptr)_2)->base + 2);
    _2 = (int)SEQ_PTR(_10buckets);
    _2 = (int)(((s1_ptr)_2)->base + _hashval);
    _1 = *(int *)_2;
    *(int *)_2 = _1334;
    DeRef(_1);

    //     return tok  -- no ref on newly declared symbol
    DeRefDS(_word);
    DeRef(_gtok);
    DeRef(_1306);
    return _tok;
    ;
}


int _10Hide(int _s)
{
    int _prev;
    int _p;
    int _1364 = 0;
    int _1353 = 0;
    int _1348 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     p = buckets[SymTab[s][S_HASHVAL]]
    _2 = (int)SEQ_PTR(_4SymTab);
    _1348 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1348);
    _0 = _1348;
    _2 = (int)SEQ_PTR(_1348);
    _1348 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_1348);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(_10buckets);
    if (!IS_ATOM_INT(_1348))
        _p = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1348)->dbl));
    else
        _p = (int)*(((s1_ptr)_2)->base + _1348);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     prev = 0
    _prev = 0;

    //     while p != s and p != 0 do
L1:
    DeRef(_1348);
    _1348 = (_p != _s);
    if (_1348 == 0) {
        goto L2;
    }
    DeRef(_1353);
    _1353 = (_p != 0);
L3:
    if (_1353 == 0)
        goto L2;

    // 	prev = p
    _prev = _p;

    // 	p = SymTab[p][S_SAMEHASH]
    DeRef(_1353);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1353 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_1353);
    _2 = (int)SEQ_PTR(_1353);
    _p = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     end while
    goto L1;
L2:

    //     if p = 0 then
    if (_p != 0)
        goto L4;

    // 	return -- already hidden 
    DeRef(_1364);
    DeRef(_1353);
    DeRef(_1348);
    return 0;
L4:

    //     if prev = 0 then
    if (_prev != 0)
        goto L5;

    // 	buckets[SymTab[s][S_HASHVAL]] = SymTab[s][S_SAMEHASH]
    DeRef(_1353);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1353 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1353);
    _0 = _1353;
    _2 = (int)SEQ_PTR(_1353);
    _1353 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_1353);
    DeRefDS(_0);
    DeRef(_1348);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1348 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1348);
    _0 = _1348;
    _2 = (int)SEQ_PTR(_1348);
    _1348 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1348);
    DeRefDS(_0);
    Ref(_1348);
    _2 = (int)SEQ_PTR(_10buckets);
    if (!IS_ATOM_INT(_1353))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_1353)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _1353);
    _1 = *(int *)_2;
    *(int *)_2 = _1348;
    DeRef(_1);
    goto L6;
L5:

    // 	SymTab[prev][S_SAMEHASH] = SymTab[s][S_SAMEHASH]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev + ((s1_ptr)_2)->base);
    DeRef(_1364);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1364 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1364);
    _0 = _1364;
    _2 = (int)SEQ_PTR(_1364);
    _1364 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_1364);
    DeRefDS(_0);
    Ref(_1364);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _1364;
    DeRef(_1);
L6:

    // end procedure
    DeRef(_1364);
    DeRef(_1353);
    DeRef(_1348);
    return 0;
    ;
}


int _10LintCheck(int _s)
{
    int _u;
    int _n;
    int _vtype = 0;
    int _place = 0;
    int _problem = 0;
    int _file = 0;
    int _1393 = 0;
    int _1391;
    int _1366 = 0;
    int _0, _1, _2;
    

    //     u = SymTab[s][S_USAGE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1366);
    _2 = (int)SEQ_PTR(_1366);
    _u = (int)*(((s1_ptr)_2)->base + 5);
    if (!IS_ATOM_INT(_u))
        _u = (long)DBL_PTR(_u)->dbl;

    //     file = name_ext(file_name[current_file_no])
    DeRefDS(_1366);
    _2 = (int)SEQ_PTR(_4file_name);
    _1366 = (int)*(((s1_ptr)_2)->base + _4current_file_no);
    RefDS(_1366);
    RefDS(_1366);
    _file = _10name_ext(_1366);

    //     if SymTab[s][S_SCOPE] = SC_LOCAL then
    DeRefDS(_1366);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1366);
    _0 = _1366;
    _2 = (int)SEQ_PTR(_1366);
    _1366 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1366);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _1366, 5))
        goto L1;

    // 	if SymTab[s][S_MODE] = M_CONSTANT then
    DeRef(_1366);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1366);
    _0 = _1366;
    _2 = (int)SEQ_PTR(_1366);
    _1366 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1366);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _1366, 2))
        goto L2;

    // 	    vtype = "local constant"
    RefDS(_1376);
    _vtype = _1376;
    goto L3;
L2:

    // 	    vtype = "local variable"
    RefDS(_1377);
    DeRefi(_vtype);
    _vtype = _1377;
L3:

    // 	place = ""
    RefDS(_39);
    DeRef(_place);
    _place = _39;
    goto L4;
L1:

    // 	n = SymTab[CurrentSub][S_NUM_ARGS]
    DeRef(_1366);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1366);
    _2 = (int)SEQ_PTR(_1366);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 	if SymTab[s][S_VARNUM] < n then
    DeRefDS(_1366);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1366);
    _0 = _1366;
    _2 = (int)SEQ_PTR(_1366);
    _1366 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_1366);
    DeRefDS(_0);
    if (binary_op_a(GREATEREQ, _1366, _n))
        goto L5;

    // 	    vtype = "parameter"
    RefDS(_1383);
    DeRefi(_vtype);
    _vtype = _1383;
    goto L6;
L5:

    // 	    vtype = "private variable"
    RefDS(_1384);
    DeRefi(_vtype);
    _vtype = _1384;
L6:

    // 	place = SymTab[CurrentSub][S_NAME]
    DeRef(_1366);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1366 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1366);
    DeRef(_place);
    _2 = (int)SEQ_PTR(_1366);
    _place = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_place);
L4:

    //     problem = ""
    RefDS(_39);
    DeRefi(_problem);
    _problem = _39;

    //     if u != or_bits(U_READ, U_WRITTEN) then
    DeRef(_1366);
    _1366 = (1 | 2);
    if (_u == _1366)
        goto L7;

    // 	if u = U_UNUSED or 
    _1366 = (_u == 0);
    if (_1366 != 0) {
        goto L8;
    }
    _1391 = (_u == 2);
    if (_1391 == 0) {
        _1391 = 0;
        goto L9;
    }
    DeRef(_1393);
    if (_vtype == _1376)
        _1393 = 1;
    else if (IS_ATOM_INT(_vtype) && IS_ATOM_INT(_1376))
        _1393 = 0;
    else
        _1393 = (compare(_vtype, _1376) == 0);
    _1391 = (_1393 != 0);
L9:
LA:
    if (_1391 == 0)
        goto LB;
L8:

    // 	    problem = "not used" 
    RefDS(_1394);
    DeRefi(_problem);
    _problem = _1394;
    goto LC;
LB:

    // 	elsif u = U_READ then
    if (_u != 1)
        goto LD;

    // 	    problem = "never assigned a value"
    RefDS(_1396);
    DeRefi(_problem);
    _problem = _1396;
LD:
LC:

    // 	if length(problem) then
    DeRef(_1393);
    _1393 = SEQ_PTR(_problem)->length;
    if (_1393 == 0)
        goto LE;

    // 	    if length(place) then
    _1393 = SEQ_PTR(_place)->length;
    if (_1393 == 0)
        goto LF;

    // 		Warning(sprintf("%s %s in %s() in %s is %s", 
    _2 = (int)SEQ_PTR(_4SymTab);
    _1393 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1393);
    _0 = _1393;
    _2 = (int)SEQ_PTR(_1393);
    _1393 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1393);
    DeRefDS(_0);
    _0 = _1393;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_vtype);
    *((int *)(_2+4)) = _vtype;
    Ref(_1393);
    *((int *)(_2+8)) = _1393;
    RefDS(_place);
    *((int *)(_2+12)) = _place;
    RefDS(_file);
    *((int *)(_2+16)) = _file;
    RefDS(_problem);
    *((int *)(_2+20)) = _problem;
    _1393 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _1393;
    _1393 = EPrintf(-9999999, _1399, _1393);
    DeRefDS(_0);
    RefDS(_1393);
    _6Warning(_1393);
    goto L10;
LF:

    // 		Warning(sprintf("%s %s in %s is %s", 
    DeRef(_1393);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1393 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1393);
    _0 = _1393;
    _2 = (int)SEQ_PTR(_1393);
    _1393 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_1393);
    DeRefDS(_0);
    _0 = _1393;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_vtype);
    *((int *)(_2+4)) = _vtype;
    Ref(_1393);
    *((int *)(_2+8)) = _1393;
    RefDS(_file);
    *((int *)(_2+12)) = _file;
    RefDS(_problem);
    *((int *)(_2+16)) = _problem;
    _1393 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _1393;
    _1393 = EPrintf(-9999999, _1404, _1393);
    DeRefDS(_0);
    RefDS(_1393);
    _6Warning(_1393);
L10:
LE:
L7:

    // end procedure
    DeRefi(_vtype);
    DeRef(_place);
    DeRefi(_problem);
    DeRef(_file);
    DeRef(_1393);
    DeRef(_1366);
    return 0;
    ;
}


int _10HideLocals()
{
    int _s;
    int _1413 = 0;
    int _1409 = 0;
    int _0, _1, _2;
    

    //     s = file_start_sym
    _s = _4file_start_sym;

    //     while s do 
L1:
    if (_s == 0)
        goto L2;

    // 	if SymTab[s][S_SCOPE] = SC_LOCAL and 
    DeRef(_1409);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1409 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1409);
    _0 = _1409;
    _2 = (int)SEQ_PTR(_1409);
    _1409 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1409);
    DeRefDS(_0);
    _0 = _1409;
    if (IS_ATOM_INT(_1409)) {
        _1409 = (_1409 == 5);
    }
    else {
        _1409 = binary_op(EQUALS, _1409, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1409)) {
        if (_1409 == 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_1409)->dbl == 0.0) {
            goto L3;
        }
    }
    DeRef(_1413);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1413 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1413);
    _0 = _1413;
    _2 = (int)SEQ_PTR(_1413);
    _1413 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_1413);
    DeRefDS(_0);
    _0 = _1413;
    if (IS_ATOM_INT(_1413)) {
        _1413 = (_1413 == _4current_file_no);
    }
    else {
        _1413 = binary_op(EQUALS, _1413, _4current_file_no);
    }
    DeRef(_0);
L4:
    if (_1413 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_1413) && DBL_PTR(_1413)->dbl == 0.0)
            goto L3;
    }

    // 	    Hide(s)
    _10Hide(_s);

    // 	    if SymTab[s][S_TOKEN] = VARIABLE then
    DeRef(_1413);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1413 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1413);
    _0 = _1413;
    _2 = (int)SEQ_PTR(_1413);
    _1413 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_1413);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _1413, -100))
        goto L5;

    // 		LintCheck(s)
    _10LintCheck(_s);
L5:
L3:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_1413);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1413 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1413);
    _2 = (int)SEQ_PTR(_1413);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    // end procedure
    DeRef(_1413);
    DeRef(_1409);
    return 0;
    ;
}


int _10ExitScope()
{
    int _s;
    int _1424 = 0;
    int _1421 = 0;
    int _0, _1, _2;
    

    //     s = SymTab[CurrentSub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _1421 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_1421);
    _2 = (int)SEQ_PTR(_1421);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s and SymTab[s][S_SCOPE] = SC_PRIVATE do
L1:
    if (_s == 0) {
        goto L2;
    }
    DeRef(_1424);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1424 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1424);
    _0 = _1424;
    _2 = (int)SEQ_PTR(_1424);
    _1424 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1424);
    DeRefDS(_0);
    _0 = _1424;
    if (IS_ATOM_INT(_1424)) {
        _1424 = (_1424 == 3);
    }
    else {
        _1424 = binary_op(EQUALS, _1424, 3);
    }
    DeRef(_0);
L3:
    if (_1424 <= 0) {
        if (_1424 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_1424) && DBL_PTR(_1424)->dbl == 0.0)
                goto L2;
        }
    }

    // 	Hide(s) 
    _10Hide(_s);

    // 	LintCheck(s)
    _10LintCheck(_s);

    // 	s = SymTab[s][S_NEXT]
    DeRef(_1424);
    _2 = (int)SEQ_PTR(_4SymTab);
    _1424 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_1424);
    _2 = (int)SEQ_PTR(_1424);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while 
    goto L1;
L2:

    // end procedure
    DeRef(_1424);
    DeRef(_1421);
    return 0;
    ;
}


