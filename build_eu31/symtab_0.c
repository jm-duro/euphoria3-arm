// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

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


