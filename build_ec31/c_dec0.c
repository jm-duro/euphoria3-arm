// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16c_stmt(int _stmt, int _arg)
{
    int _argcount;
    int _i;
    int _4397 = 0;
    int _4390 = 0;
    int _0, _1, _2;
    

    //     if Pass = LAST_PASS then
    if (_16Pass != 7)
        goto L1;

    // 	cfile_size += 1
    _4cfile_size = _4cfile_size + 1;
L1:

    //     adjust_indent_before(stmt)
    RefDS(_stmt);
    _9adjust_indent_before(_stmt);

    //     if atom(arg) then 
    DeRef(_4390);
    _4390 = IS_ATOM(_arg);
    if (_4390 == 0)
        goto L2;

    // 	arg = {arg}
    _0 = _arg;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_arg);
    *((int *)(_2+4)) = _arg;
    _arg = MAKE_SEQ(_1);
    DeRef(_0);
L2:

    //     argcount = 1
    _argcount = 1;

    //     i = 1
    _i = 1;

    //     while i <= length(stmt) and length(stmt) > 0 do
L3:
    DeRef(_4390);
    _4390 = SEQ_PTR(_stmt)->length;
    _4390 = (_i <= _4390);
    if (_4390 == 0) {
        goto L4;
    }
    DeRef(_4397);
    _4397 = SEQ_PTR(_stmt)->length;
    _4397 = (_4397 > 0);
L5:
    if (_4397 == 0)
        goto L4;

    // 	if stmt[i] = '@' then
    DeRef(_4397);
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_4397);
    if (binary_op_a(NOTEQ, _4397, 64))
        goto L6;

    // 	    if i = 1 then
    if (_i != 1)
        goto L7;

    // 		LeftSym = TRUE
    _16LeftSym = 1;
L7:

    // 	    if i < length(stmt) and stmt[i+1] > '0' and stmt[i+1] <= '9' then
    DeRef(_4397);
    _4397 = SEQ_PTR(_stmt)->length;
    _4397 = (_i < _4397);
    if (_4397 == 0) {
        _4397 = 0;
        goto L8;
    }
    DeRef(_4390);
    _4390 = _i + 1;
    _2 = (int)SEQ_PTR(_stmt);
    _4390 = (int)*(((s1_ptr)_2)->base + _4390);
    Ref(_4390);
    _0 = _4390;
    if (IS_ATOM_INT(_4390)) {
        _4390 = (_4390 > 48);
    }
    else {
        _4390 = binary_op(GREATER, _4390, 48);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4390))
        _4397 = (_4390 != 0);
    else
        _4397 = DBL_PTR(_4390)->dbl != 0.0;
L8:
    if (_4397 == 0) {
        goto L9;
    }
    DeRef(_4397);
    _4397 = _i + 1;
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _4397);
    Ref(_4397);
    _0 = _4397;
    if (IS_ATOM_INT(_4397)) {
        _4397 = (_4397 <= 57);
    }
    else {
        _4397 = binary_op(LESSEQ, _4397, 57);
    }
    DeRef(_0);
LA:
    if (_4397 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_4397) && DBL_PTR(_4397)->dbl == 0.0)
            goto L9;
    }

    // 		CName(arg[stmt[i+1]-'0'])
    DeRef(_4397);
    _4397 = _i + 1;
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _4397);
    Ref(_4397);
    _0 = _4397;
    if (IS_ATOM_INT(_4397)) {
        _4397 = _4397 - 48;
    }
    else {
        _4397 = binary_op(MINUS, _4397, 48);
    }
    DeRef(_0);
    _0 = _4397;
    _2 = (int)SEQ_PTR(_arg);
    if (!IS_ATOM_INT(_4397))
        _4397 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4397)->dbl));
    else
        _4397 = (int)*(((s1_ptr)_2)->base + _4397);
    Ref(_4397);
    DeRef(_0);
    Ref(_4397);
    _16CName(_4397);

    // 		i += 1
    _i = _i + 1;
    goto LB;
L9:

    // 		CName(arg[argcount])
    DeRef(_4397);
    _2 = (int)SEQ_PTR(_arg);
    _4397 = (int)*(((s1_ptr)_2)->base + _argcount);
    Ref(_4397);
    Ref(_4397);
    _16CName(_4397);
LB:

    // 	    argcount += 1
    _argcount = _argcount + 1;
    goto LC;
L6:

    // 	    c_putc(stmt[i])
    DeRef(_4397);
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_4397);
    Ref(_4397);
    _9c_putc(_4397);

    // 	    if stmt[i] = '&' and i < length(stmt) and stmt[i+1] = '@' then
    DeRef(_4397);
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_4397);
    _0 = _4397;
    if (IS_ATOM_INT(_4397)) {
        _4397 = (_4397 == 38);
    }
    else {
        _4397 = binary_op(EQUALS, _4397, 38);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4397)) {
        if (_4397 == 0) {
            DeRef(_4397);
            _4397 = 0;
            goto LD;
        }
    }
    else {
        if (DBL_PTR(_4397)->dbl == 0.0) {
            DeRef(_4397);
            _4397 = 0;
            goto LD;
        }
    }
    DeRef(_4390);
    _4390 = SEQ_PTR(_stmt)->length;
    _4390 = (_i < _4390);
    DeRef(_4397);
    _4397 = (_4390 != 0);
LD:
    if (_4397 == 0) {
        goto LE;
    }
    DeRef(_4397);
    _4397 = _i + 1;
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _4397);
    Ref(_4397);
    _0 = _4397;
    if (IS_ATOM_INT(_4397)) {
        _4397 = (_4397 == 64);
    }
    else {
        _4397 = binary_op(EQUALS, _4397, 64);
    }
    DeRef(_0);
LF:
    if (_4397 == 0) {
        goto LE;
    }
    else {
        if (!IS_ATOM_INT(_4397) && DBL_PTR(_4397)->dbl == 0.0)
            goto LE;
    }

    // 		LeftSym = TRUE -- never say: x = x &y or andy - always leave space
    _16LeftSym = 1;
LE:
LC:

    // 	if stmt[i] = '\n' and i < length(stmt) then
    DeRef(_4397);
    _2 = (int)SEQ_PTR(_stmt);
    _4397 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_4397);
    _0 = _4397;
    if (IS_ATOM_INT(_4397)) {
        _4397 = (_4397 == 10);
    }
    else {
        _4397 = binary_op(EQUALS, _4397, 10);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4397)) {
        if (_4397 == 0) {
            goto L10;
        }
    }
    else {
        if (DBL_PTR(_4397)->dbl == 0.0) {
            goto L10;
        }
    }
    DeRef(_4390);
    _4390 = SEQ_PTR(_stmt)->length;
    _4390 = (_i < _4390);
L11:
    if (_4390 == 0)
        goto L10;

    // 	    adjust_indent_after(stmt)
    RefDS(_stmt);
    _9adjust_indent_after(_stmt);

    // 	    stmt = stmt[i+1..$]
    DeRef(_4390);
    _4390 = _i + 1;
    if (_4390 > MAXINT)
        _4390 = NewDouble((double)_4390);
    DeRef(_4397);
    _4397 = SEQ_PTR(_stmt)->length;
    rhs_slice_target = (object_ptr)&_stmt;
    RHS_Slice((s1_ptr)_stmt, _4390, _4397);

    // 	    i = 0
    _i = 0;

    // 	    adjust_indent_before(stmt)
    RefDS(_stmt);
    _9adjust_indent_before(_stmt);
L10:

    // 	i += 1
    _i = _i + 1;

    //     end while
    goto L3;
L4:

    //     adjust_indent_after(stmt)
    RefDS(_stmt);
    _9adjust_indent_after(_stmt);

    // end procedure
    DeRefDS(_stmt);
    DeRef(_arg);
    DeRef(_4397);
    DeRef(_4390);
    return 0;
    ;
}


int _16c_stmt0(int _stmt)
{
    int _0, _1, _2;
    

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	c_stmt(stmt, {})
    RefDS(_stmt);
    RefDS(_39);
    _16c_stmt(_stmt, _39);
L1:

    // end procedure
    DeRefDS(_stmt);
    return 0;
    ;
}


int _16DeclareFileVars()
{
    int _s;
    int _entry = 0;
    int _4454 = 0;
    int _4438 = 0;
    int _4444 = 0;
    int _0, _1, _2;
    

    //     c_puts("\n")
    RefDS(_629);
    _9c_puts(_629);

    //     s = SymTab[TopLevelSub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4438 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4438);
    _2 = (int)SEQ_PTR(_4438);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
L1:
    if (_s == 0)
        goto L2;

    // 	entry = SymTab[s]
    DeRef(_entry);
    _2 = (int)SEQ_PTR(_4SymTab);
    _entry = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_entry);

    // 	if entry[S_SCOPE] >= SC_LOCAL and entry[S_SCOPE] <= SC_GLOBAL and
    DeRef(_4438);
    _2 = (int)SEQ_PTR(_entry);
    _4438 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4438);
    _0 = _4438;
    if (IS_ATOM_INT(_4438)) {
        _4438 = (_4438 >= 5);
    }
    else {
        _4438 = binary_op(GREATEREQ, _4438, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4438)) {
        if (_4438 == 0) {
            DeRef(_4438);
            _4438 = 0;
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4438)->dbl == 0.0) {
            DeRef(_4438);
            _4438 = 0;
            goto L3;
        }
    }
    DeRef(_4444);
    _2 = (int)SEQ_PTR(_entry);
    _4444 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4444);
    _0 = _4444;
    if (IS_ATOM_INT(_4444)) {
        _4444 = (_4444 <= 6);
    }
    else {
        _4444 = binary_op(LESSEQ, _4444, 6);
    }
    DeRef(_0);
    DeRef(_4438);
    if (IS_ATOM_INT(_4444))
        _4438 = (_4444 != 0);
    else
        _4438 = DBL_PTR(_4444)->dbl != 0.0;
L3:
    if (_4438 == 0) {
        DeRef(_4444);
        _4444 = 0;
        goto L4;
    }
    DeRef(_4438);
    _2 = (int)SEQ_PTR(_entry);
    _4438 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4438);
    _0 = _4438;
    if (IS_ATOM_INT(_4438)) {
        _4438 = (_4438 != 0);
    }
    else {
        _4438 = binary_op(NOTEQ, _4438, 0);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4438))
        _4444 = (_4438 != 0);
    else
        _4444 = DBL_PTR(_4438)->dbl != 0.0;
L4:
    if (_4444 == 0) {
        DeRef(_4438);
        _4438 = 0;
        goto L5;
    }
    DeRef(_4444);
    _2 = (int)SEQ_PTR(_entry);
    _4444 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4444);
    _0 = _4444;
    if (IS_ATOM_INT(_4444)) {
        _4444 = (_4444 != 99);
    }
    else {
        _4444 = binary_op(NOTEQ, _4444, 99);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4444))
        _4438 = (_4444 != 0);
    else
        _4438 = DBL_PTR(_4444)->dbl != 0.0;
L5:
    if (_4438 == 0) {
        goto L6;
    }
    DeRef(_4438);
    _2 = (int)SEQ_PTR(_entry);
    _4438 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4438);
    _0 = _4454;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _4454 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4454;
    _4454 = find(_4438, _4454);
    DeRefDSi(_0);
    _4454 = (_4454 == 0);
L7:
    if (_4454 == 0)
        goto L6;

    // 	    c_puts("int ")
    RefDS(_4457);
    _9c_puts(_4457);

    // 	    c_printf("_%d", entry[S_FILE_NO])
    DeRef(_4454);
    _2 = (int)SEQ_PTR(_entry);
    _4454 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4454);
    RefDS(_4345);
    Ref(_4454);
    _9c_printf(_4345, _4454);

    // 	    c_puts(entry[S_NAME])
    DeRef(_4454);
    _2 = (int)SEQ_PTR(_entry);
    _4454 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4454);
    Ref(_4454);
    _9c_puts(_4454);

    // 	    c_puts(";\n")
    RefDS(_4460);
    _9c_puts(_4460);

    // 	    c_hputs("extern int ")
    RefDS(_4461);
    _9c_hputs(_4461);

    // 	    c_hprintf("_%d", entry[S_FILE_NO])
    DeRef(_4454);
    _2 = (int)SEQ_PTR(_entry);
    _4454 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4454);
    RefDS(_4345);
    Ref(_4454);
    _9c_hprintf(_4345, _4454);

    // 	    c_hputs(entry[S_NAME])
    DeRef(_4454);
    _2 = (int)SEQ_PTR(_entry);
    _4454 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4454);
    Ref(_4454);
    _9c_hputs(_4454);

    // 	    c_hputs(";\n")
    RefDS(_4460);
    _9c_hputs(_4460);
L6:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4454);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4454 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4454);
    _2 = (int)SEQ_PTR(_4454);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    //     c_puts("\n")
    RefDS(_629);
    _9c_puts(_629);

    //     c_hputs("\n")
    RefDS(_629);
    _9c_hputs(_629);

    // end procedure
    DeRef(_entry);
    DeRef(_4454);
    DeRef(_4438);
    DeRef(_4444);
    return 0;
    ;
}


int _16PromoteTypeInfo()
{
    int _s;
    int _4466 = 0;
    int _4645 = 0;
    int _4472 = 0;
    int _4482 = 0;
    int _0, _1, _2, _3;
    

    //     s = SymTab[TopLevelSub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4466);
    _2 = (int)SEQ_PTR(_4466);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
L1:
    if (_s == 0)
        goto L2;

    // 	if SymTab[s][S_TOKEN] = FUNC or SymTab[s][S_TOKEN] = TYPE then
    DeRef(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4466);
    DeRefDS(_0);
    _0 = _4466;
    if (IS_ATOM_INT(_4466)) {
        _4466 = (_4466 == 501);
    }
    else {
        _4466 = binary_op(EQUALS, _4466, 501);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4466)) {
        if (_4466 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4466)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4472);
    DeRefDS(_0);
    _0 = _4472;
    if (IS_ATOM_INT(_4472)) {
        _4472 = (_4472 == 504);
    }
    else {
        _4472 = binary_op(EQUALS, _4472, 504);
    }
    DeRef(_0);
L4:
    if (_4472 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_4472) && DBL_PTR(_4472)->dbl == 0.0)
            goto L5;
    }
L3:

    // 	    if SymTab[s][S_GTYPE_NEW] = TYPE_NULL then
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4472);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4472, 0))
        goto L6;

    // 		SymTab[s][S_GTYPE] = TYPE_OBJECT
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
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);
    goto L7;
L6:

    // 		SymTab[s][S_GTYPE] = SymTab[s][S_GTYPE_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4482);
    DeRefDS(_0);
    Ref(_4482);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = _4482;
    DeRef(_1);
L8:
    goto L7;
L5:

    // 	    if SymTab[s][S_GTYPE] != TYPE_INTEGER and
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_4482);
    DeRefDS(_0);
    _0 = _4482;
    if (IS_ATOM_INT(_4482)) {
        _4482 = (_4482 != 1);
    }
    else {
        _4482 = binary_op(NOTEQ, _4482, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4482)) {
        if (_4482 == 0) {
            DeRef(_4482);
            _4482 = 0;
            goto L9;
        }
    }
    else {
        if (DBL_PTR(_4482)->dbl == 0.0) {
            DeRef(_4482);
            _4482 = 0;
            goto L9;
        }
    }
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4472);
    DeRefDS(_0);
    _0 = _4472;
    if (IS_ATOM_INT(_4472)) {
        _4472 = (_4472 != 16);
    }
    else {
        _4472 = binary_op(NOTEQ, _4472, 16);
    }
    DeRef(_0);
    DeRef(_4482);
    if (IS_ATOM_INT(_4472))
        _4482 = (_4472 != 0);
    else
        _4482 = DBL_PTR(_4472)->dbl != 0.0;
L9:
    if (_4482 == 0) {
        goto LA;
    }
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4482);
    DeRefDS(_0);
    _0 = _4482;
    if (IS_ATOM_INT(_4482)) {
        _4482 = (_4482 != 0);
    }
    else {
        _4482 = binary_op(NOTEQ, _4482, 0);
    }
    DeRef(_0);
LB:
    if (_4482 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_4482) && DBL_PTR(_4482)->dbl == 0.0)
            goto LA;
    }

    // 		if SymTab[s][S_GTYPE_NEW] = TYPE_INTEGER or
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4482);
    DeRefDS(_0);
    _0 = _4482;
    if (IS_ATOM_INT(_4482)) {
        _4482 = (_4482 == 1);
    }
    else {
        _4482 = binary_op(EQUALS, _4482, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4482)) {
        if (_4482 != 0) {
            DeRef(_4482);
            _4482 = 1;
            goto LC;
        }
    }
    else {
        if (DBL_PTR(_4482)->dbl != 0.0) {
            DeRef(_4482);
            _4482 = 1;
            goto LC;
        }
    }
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_4472);
    DeRefDS(_0);
    _0 = _4472;
    if (IS_ATOM_INT(_4472)) {
        _4472 = (_4472 == 16);
    }
    else {
        _4472 = binary_op(EQUALS, _4472, 16);
    }
    DeRef(_0);
    DeRef(_4482);
    if (IS_ATOM_INT(_4472))
        _4482 = (_4472 != 0);
    else
        _4482 = DBL_PTR(_4472)->dbl != 0.0;
LC:
    if (_4482 != 0) {
        goto LD;
    }
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_4482);
    DeRefDS(_0);
    _0 = _4482;
    if (IS_ATOM_INT(_4482)) {
        _4482 = (_4482 == 4);
    }
    else {
        _4482 = binary_op(EQUALS, _4482, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4482)) {
        if (_4482 == 0) {
            DeRef(_4482);
            _4482 = 0;
            goto LE;
        }
    }
    else {
        if (DBL_PTR(_4482)->dbl == 0.0) {
            DeRef(_4482);
            _4482 = 0;
            goto LE;
        }
    }
    DeRef(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4466);
    DeRefDS(_0);
    _0 = _4466;
    if (IS_ATOM_INT(_4466)) {
        _4466 = (_4466 == 2);
    }
    else {
        _4466 = binary_op(EQUALS, _4466, 2);
    }
    DeRef(_0);
    DeRef(_4482);
    if (IS_ATOM_INT(_4466))
        _4482 = (_4466 != 0);
    else
        _4482 = DBL_PTR(_4466)->dbl != 0.0;
LE:
LF:
    if (_4482 == 0)
        goto L10;
LD:

    // 			SymTab[s][S_GTYPE] = SymTab[s][S_GTYPE_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4472);
    DeRefDS(_0);
    Ref(_4472);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = _4472;
    DeRef(_1);
L10:
LA:

    // 	    if SymTab[s][S_ARG_TYPE_NEW] = TYPE_NULL then
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 41);
    Ref(_4472);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4472, 0))
        goto L11;

    // 		SymTab[s][S_ARG_TYPE] = TYPE_OBJECT
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
    _2 = (int)(((s1_ptr)_2)->base + 40);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);
    goto L12;
L11:

    // 		SymTab[s][S_ARG_TYPE] = SymTab[s][S_ARG_TYPE_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 41);
    Ref(_4466);
    DeRefDS(_0);
    Ref(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 40);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);
L12:

    // 	    SymTab[s][S_ARG_TYPE_NEW] = TYPE_NULL
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
    _2 = (int)(((s1_ptr)_2)->base + 41);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	    if SymTab[s][S_ARG_SEQ_ELEM_NEW] = TYPE_NULL then
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 43);
    Ref(_4472);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4472, 0))
        goto L13;

    // 		SymTab[s][S_ARG_SEQ_ELEM] = TYPE_OBJECT
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
    _2 = (int)(((s1_ptr)_2)->base + 42);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);
    goto L14;
L13:

    // 		SymTab[s][S_ARG_SEQ_ELEM] = SymTab[s][S_ARG_SEQ_ELEM_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 43);
    Ref(_4482);
    DeRefDS(_0);
    Ref(_4482);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 42);
    _1 = *(int *)_2;
    *(int *)_2 = _4482;
    DeRef(_1);
L14:

    // 	    SymTab[s][S_ARG_SEQ_ELEM_NEW] = TYPE_NULL
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
    _2 = (int)(((s1_ptr)_2)->base + 43);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	    if SymTab[s][S_ARG_MIN_NEW] = -NOVALUE or 
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 46);
    Ref(_4472);
    DeRefDS(_0);
    DeRef(_4482);
    _4482 = unary_op(UMINUS, _4NOVALUE);
    _0 = _4482;
    _4482 = binary_op(EQUALS, _4472, _4482);
    DeRefDS(_0);
    if (IS_ATOM_INT(_4482)) {
        if (_4482 != 0) {
            goto L15;
        }
    }
    else {
        if (DBL_PTR(_4482)->dbl != 0.0) {
            goto L15;
        }
    }
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 46);
    Ref(_4472);
    DeRefDS(_0);
    _0 = _4472;
    _4472 = binary_op(EQUALS, _4472, _4NOVALUE);
    DeRef(_0);
L16:
    if (_4472 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_4472) && DBL_PTR(_4472)->dbl == 0.0)
            goto L17;
    }
L15:

    // 		SymTab[s][S_ARG_MIN] = MININT
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
    _2 = (int)(((s1_ptr)_2)->base + 44);
    _1 = *(int *)_2;
    *(int *)_2 = -1073741824;
    DeRef(_1);

    // 		SymTab[s][S_ARG_MAX] = MAXINT
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
    _2 = (int)(((s1_ptr)_2)->base + 45);
    _1 = *(int *)_2;
    *(int *)_2 = 1073741823;
    DeRef(_1);
    goto L18;
L17:

    // 		SymTab[s][S_ARG_MIN] = SymTab[s][S_ARG_MIN_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 46);
    Ref(_4466);
    DeRefDS(_0);
    Ref(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 44);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);

    // 		SymTab[s][S_ARG_MAX] = SymTab[s][S_ARG_MAX_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 47);
    Ref(_4472);
    DeRefDS(_0);
    Ref(_4472);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 45);
    _1 = *(int *)_2;
    *(int *)_2 = _4472;
    DeRef(_1);
L18:

    // 	    SymTab[s][S_ARG_MIN_NEW] = -NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _4466 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 46);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);

    // 	    if SymTab[s][S_ARG_SEQ_LEN_NEW] = -NOVALUE then
    DeRefDS(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 49);
    Ref(_4466);
    DeRefDS(_0);
    DeRef(_4482);
    _4482 = unary_op(UMINUS, _4NOVALUE);
    if (binary_op_a(NOTEQ, _4466, _4482))
        goto L19;

    // 		SymTab[s][S_ARG_SEQ_LEN] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 48);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L1A;
L19:

    // 		SymTab[s][S_ARG_SEQ_LEN] = SymTab[s][S_ARG_SEQ_LEN_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 49);
    Ref(_4472);
    DeRefDS(_0);
    Ref(_4472);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 48);
    _1 = *(int *)_2;
    *(int *)_2 = _4472;
    DeRef(_1);
L1A:

    // 	    SymTab[s][S_ARG_SEQ_LEN_NEW] = -NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _4466 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 49);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);
L7:

    // 	SymTab[s][S_GTYPE_NEW] = TYPE_NULL
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
    _2 = (int)(((s1_ptr)_2)->base + 35);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	if SymTab[s][S_SEQ_ELEM_NEW] = TYPE_NULL then
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_4482);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4482, 0))
        goto L1B;

    // 	   SymTab[s][S_SEQ_ELEM] = TYPE_OBJECT
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
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = 16;
    DeRef(_1);
    goto L1C;
L1B:

    // 	    SymTab[s][S_SEQ_ELEM] = SymTab[s][S_SEQ_ELEM_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_4472);
    DeRefDS(_0);
    Ref(_4472);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = _4472;
    DeRef(_1);
L1C:

    // 	SymTab[s][S_SEQ_ELEM_NEW] = TYPE_NULL
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
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	if SymTab[s][S_SEQ_LEN_NEW] = -NOVALUE then
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 36);
    Ref(_4482);
    DeRefDS(_0);
    DeRef(_4472);
    _4472 = unary_op(UMINUS, _4NOVALUE);
    if (binary_op_a(NOTEQ, _4482, _4472))
        goto L1D;

    // 	    SymTab[s][S_SEQ_LEN] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
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
    goto L1E;
L1D:

    // 	    SymTab[s][S_SEQ_LEN] = SymTab[s][S_SEQ_LEN_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 36);
    Ref(_4466);
    DeRefDS(_0);
    Ref(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);
L1E:

    // 	SymTab[s][S_SEQ_LEN_NEW] = -NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4482);
    _4482 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_4482);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _4482;
    DeRef(_1);

    // 	if SymTab[s][S_TOKEN] != NAMESPACE then
    DeRefDS(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4482);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4482, 523))
        goto L1F;

    // 	    if SymTab[s][S_OBJ_MIN_NEW] = -NOVALUE or
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_4482);
    DeRefDS(_0);
    DeRef(_4472);
    _4472 = unary_op(UMINUS, _4NOVALUE);
    _0 = _4472;
    _4472 = binary_op(EQUALS, _4482, _4472);
    DeRefDS(_0);
    if (IS_ATOM_INT(_4472)) {
        if (_4472 != 0) {
            goto L20;
        }
    }
    else {
        if (DBL_PTR(_4472)->dbl != 0.0) {
            goto L20;
        }
    }
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_4482);
    DeRefDS(_0);
    _0 = _4482;
    _4482 = binary_op(EQUALS, _4482, _4NOVALUE);
    DeRef(_0);
L21:
    if (_4482 == 0) {
        goto L22;
    }
    else {
        if (!IS_ATOM_INT(_4482) && DBL_PTR(_4482)->dbl == 0.0)
            goto L22;
    }
L20:

    // 		SymTab[s][S_OBJ_MIN] = MININT
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
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = -1073741824;
    DeRef(_1);

    // 		SymTab[s][S_OBJ_MAX] = MAXINT
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
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = 1073741823;
    DeRef(_1);
    goto L23;
L22:

    // 		SymTab[s][S_OBJ_MIN] = SymTab[s][S_OBJ_MIN_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_4466);
    DeRefDS(_0);
    Ref(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);

    // 		SymTab[s][S_OBJ_MAX] = SymTab[s][S_OBJ_MAX_NEW]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 39);
    Ref(_4482);
    DeRefDS(_0);
    Ref(_4482);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _4482;
    DeRef(_1);
L23:
L1F:

    // 	SymTab[s][S_OBJ_MIN_NEW] = -NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4466);
    _4466 = unary_op(UMINUS, _4NOVALUE);
    RefDS(_4466);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _4466;
    DeRef(_1);

    // 	if SymTab[s][S_NREFS] = 1 and 
    DeRefDS(_4466);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4466 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4466);
    _0 = _4466;
    _2 = (int)SEQ_PTR(_4466);
    _4466 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4466);
    DeRefDS(_0);
    _0 = _4466;
    if (IS_ATOM_INT(_4466)) {
        _4466 = (_4466 == 1);
    }
    else {
        _4466 = binary_op(EQUALS, _4466, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4466)) {
        if (_4466 == 0) {
            goto L24;
        }
    }
    else {
        if (DBL_PTR(_4466)->dbl == 0.0) {
            goto L24;
        }
    }
    DeRef(_4472);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4472 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4472);
    _0 = _4472;
    _2 = (int)SEQ_PTR(_4472);
    _4472 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4472);
    DeRefDS(_0);
    _0 = _4482;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _4482 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4482;
    _4482 = find(_4472, _4482);
    DeRefDSi(_0);
L25:
    if (_4482 == 0)
        goto L24;

    // 	    if SymTab[s][S_USAGE] != U_DELETED then
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _0 = _4482;
    _2 = (int)SEQ_PTR(_4482);
    _4482 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4482);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4482, 99))
        goto L26;

    // 		SymTab[s][S_USAGE] = U_DELETED
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
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 99;
    DeRef(_1);

    // 		deleted_routines += 1
    _16deleted_routines = _16deleted_routines + 1;
L26:
L24:

    // 	SymTab[s][S_NREFS] = 0
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
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4482);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4482 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4482);
    _2 = (int)SEQ_PTR(_4482);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    //     for i = 1 to length(temp_name_type) do
    DeRef(_4482);
    _4482 = SEQ_PTR(_4temp_name_type)->length;
    { int _i;
        _i = 1;
L27:
        if (_i > _4482)
            goto L28;

        // 	temp_name_type[i][T_GTYPE] = temp_name_type[i][T_GTYPE_NEW]
        _2 = (int)SEQ_PTR(_4temp_name_type);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4temp_name_type = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_4645);
        _2 = (int)SEQ_PTR(_4temp_name_type);
        _4645 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4645);
        _0 = _4645;
        _2 = (int)SEQ_PTR(_4645);
        _4645 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4645);
        DeRefDS(_0);
        Ref(_4645);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _4645;
        DeRef(_1);

        // 	temp_name_type[i][T_GTYPE_NEW] = TYPE_NULL
        _2 = (int)SEQ_PTR(_4temp_name_type);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4temp_name_type = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 2);
        _1 = *(int *)_2;
        *(int *)_2 = 0;
        DeRef(_1);

        //     end for
        _i = _i + 1;
        goto L27;
L28:
        ;
    }

    // end procedure
    DeRef(_4466);
    DeRef(_4645);
    DeRef(_4472);
    DeRef(_4482);
    return 0;
    ;
}


int _16DeclareRoutineList()
{
    int _s;
    int _p;
    int _first;
    int _seq_num;
    int _4658 = 0;
    int _4650 = 0;
    int _4656 = 0;
    int _0, _1, _2, _3;
    

    //     c_hputs("extern struct routine_list _00[];\n")
    RefDS(_4649);
    _9c_hputs(_4649);

    //     s = SymTab[TopLevelSub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4650 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4650);
    _2 = (int)SEQ_PTR(_4650);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
L1:
    if (_s == 0)
        goto L2;

    // 	if SymTab[s][S_USAGE] != U_DELETED and
    DeRef(_4650);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4650 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4650);
    _0 = _4650;
    _2 = (int)SEQ_PTR(_4650);
    _4650 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4650);
    DeRefDS(_0);
    _0 = _4650;
    if (IS_ATOM_INT(_4650)) {
        _4650 = (_4650 != 99);
    }
    else {
        _4650 = binary_op(NOTEQ, _4650, 99);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4650)) {
        if (_4650 == 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4650)->dbl == 0.0) {
            goto L3;
        }
    }
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4656);
    DeRefDS(_0);
    _0 = _4658;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _4658 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4658;
    _4658 = find(_4656, _4658);
    DeRefDSi(_0);
L4:
    if (_4658 == 0)
        goto L3;

    // 	    if SymTab[s][S_SCOPE] = SC_GLOBAL and dll_option then
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4658);
    DeRefDS(_0);
    _0 = _4658;
    if (IS_ATOM_INT(_4658)) {
        _4658 = (_4658 == 6);
    }
    else {
        _4658 = binary_op(EQUALS, _4658, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4658)) {
        if (_4658 == 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_4658)->dbl == 0.0) {
            goto L5;
        }
    }
L6:
    if (_16dll_option == 0)
        goto L5;

    // 		if EWINDOWS then            
    if (_4EWINDOWS == 0)
        goto L7;

    // 		    c_hputs("int __stdcall\n")
    RefDS(_4664);
    _9c_hputs(_4664);
L8:
    goto L7;
L5:

    // 		c_hputs("int ")
    RefDS(_4457);
    _9c_hputs(_4457);
L7:

    // 	    c_hprintf("_%d", SymTab[s][S_FILE_NO])
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4658);
    DeRefDS(_0);
    RefDS(_4345);
    Ref(_4658);
    _9c_hprintf(_4345, _4658);

    // 	    c_hputs(SymTab[s][S_NAME])
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4658);
    DeRefDS(_0);
    Ref(_4658);
    _9c_hputs(_4658);

    // 	    c_hputs("(")
    RefDS(_4669);
    _9c_hputs(_4669);

    // 	    for i = 1 to SymTab[s][S_NUM_ARGS] do
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_4658);
    DeRefDS(_0);
    { int _i;
        _i = 1;
L9:
        if (binary_op_a(GREATER, _i, _4658))
            goto LA;

        // 		if i = 1 then
        if (binary_op_a(NOTEQ, _i, 1))
            goto LB;

        // 		    c_hputs("int")
        RefDS(_4673);
        _9c_hputs(_4673);
        goto LC;
LB:

        // 		    c_hputs(", int")
        RefDS(_4674);
        _9c_hputs(_4674);
LC:

        // 	    end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef(_0);
        goto L9;
LA:
        ;
        DeRef(_i);
    }

    // 	    c_hputs(");\n")
    RefDS(_4675);
    _9c_hputs(_4675);
L3:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _2 = (int)SEQ_PTR(_4656);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    //     c_puts("\n")
    RefDS(_629);
    _9c_puts(_629);

    //     seq_num = 0
    _seq_num = 0;

    //     first = TRUE
    _first = 1;

    //     c_puts("struct routine_list _00[] = {\n")
    RefDS(_4678);
    _9c_puts(_4678);

    //     s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4656);
    _2 = (int)SEQ_PTR(_4656);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
LD:
    if (_s == 0)
        goto LE;

    // 	if find(SymTab[s][S_TOKEN], {PROC, FUNC, TYPE, NAMESPACE}) then
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4656);
    DeRefDS(_0);
    _0 = _4658;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 523;
    _4658 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4658;
    _4658 = find(_4656, _4658);
    DeRefDSi(_0);
    if (_4658 == 0)
        goto LF;

    // 	    if SymTab[s][S_TOKEN] != NAMESPACE and SymTab[s][S_RI_TARGET] then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4658);
    DeRefDS(_0);
    _0 = _4658;
    if (IS_ATOM_INT(_4658)) {
        _4658 = (_4658 != 523);
    }
    else {
        _4658 = binary_op(NOTEQ, _4658, 523);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4658)) {
        if (_4658 == 0) {
            goto L10;
        }
    }
    else {
        if (DBL_PTR(_4658)->dbl == 0.0) {
            goto L10;
        }
    }
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 33);
    Ref(_4656);
    DeRefDS(_0);
L11:
    if (_4656 == 0) {
        goto L10;
    }
    else {
        if (!IS_ATOM_INT(_4656) && DBL_PTR(_4656)->dbl == 0.0)
            goto L10;
    }

    // 		if not first then
    if (_first != 0)
        goto L12;

    // 		    c_puts(",\n")
    RefDS(_4692);
    _9c_puts(_4692);
L12:

    // 		first = FALSE
    _first = 0;

    // 		c_puts("  {\"")
    RefDS(_4693);
    _9c_puts(_4693);

    // 		c_puts(SymTab[s][S_NAME])
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4656);
    DeRefDS(_0);
    Ref(_4656);
    _9c_puts(_4656);

    // 		c_puts("\", ")
    RefDS(_4696);
    _9c_puts(_4696);

    // 		if dll_option then
    if (_16dll_option == 0)
        goto L13;

    // 		    c_puts("(int (*)())")
    RefDS(_4697);
    _9c_puts(_4697);
L13:

    // 		c_printf("_%d", SymTab[s][S_FILE_NO])
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4656);
    DeRefDS(_0);
    RefDS(_4345);
    Ref(_4656);
    _9c_printf(_4345, _4656);

    // 		c_puts(SymTab[s][S_NAME])
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4656);
    DeRefDS(_0);
    Ref(_4656);
    _9c_puts(_4656);

    // 		c_printf(", %d", seq_num)
    RefDS(_4702);
    _9c_printf(_4702, _seq_num);

    // 		if SymTab[s][S_SCOPE] = SC_GLOBAL then
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4656);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4656, 6))
        goto L14;

    // 		    c_printf(", %d", - SymTab[s][S_FILE_NO])
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4656);
    DeRefDS(_0);
    _0 = _4656;
    if (IS_ATOM_INT(_4656)) {
        if (_4656 == 0xC0000000)
            _4656 = (int)NewDouble((double)-0xC0000000);
        else
            _4656 = - _4656;
    }
    else {
        _4656 = unary_op(UMINUS, _4656);
    }
    DeRef(_0);
    RefDS(_4702);
    Ref(_4656);
    _9c_printf(_4702, _4656);
    goto L15;
L14:

    // 		    c_printf(", %d", SymTab[s][S_FILE_NO])
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4656);
    DeRefDS(_0);
    RefDS(_4702);
    Ref(_4656);
    _9c_printf(_4702, _4656);
L15:

    // 		c_printf(", %d", SymTab[s][S_NUM_ARGS])
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_4656);
    DeRefDS(_0);
    RefDS(_4702);
    Ref(_4656);
    _9c_printf(_4702, _4656);

    // 		if EWINDOWS and dll_option and SymTab[s][S_SCOPE] = SC_GLOBAL then
    if (_4EWINDOWS == 0) {
        DeRef(_4656);
        _4656 = 0;
        goto L16;
    }
    _4656 = (_16dll_option != 0);
L16:
    if (_4656 == 0) {
        goto L17;
    }
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4658);
    DeRefDS(_0);
    _0 = _4658;
    if (IS_ATOM_INT(_4658)) {
        _4658 = (_4658 == 6);
    }
    else {
        _4658 = binary_op(EQUALS, _4658, 6);
    }
    DeRef(_0);
L18:
    if (_4658 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_4658) && DBL_PTR(_4658)->dbl == 0.0)
            goto L17;
    }

    // 		    c_puts(", 1")  -- must call with __stdcall convention
    RefDS(_4718);
    _9c_puts(_4718);
    goto L19;
L17:

    // 		    c_puts(", 0")  -- default: call with normal or __cdecl convention
    RefDS(_4719);
    _9c_puts(_4719);
L19:

    // 		c_puts("}")
    RefDS(_34);
    _9c_puts(_34);

    // 		if SymTab[s][S_NREFS] < 2 then
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _0 = _4658;
    _2 = (int)SEQ_PTR(_4658);
    _4658 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4658);
    DeRefDS(_0);
    if (binary_op_a(GREATEREQ, _4658, 2))
        goto L1A;

    // 		    SymTab[s][S_NREFS] = 2 --s->nrefs++
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
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);
L1A:

    // 		p = SymTab[s][S_NEXT]
    DeRef(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _2 = (int)SEQ_PTR(_4656);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 		for i = 1 to SymTab[s][S_NUM_ARGS] do
    DeRefDS(_4656);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4656 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4656);
    _0 = _4656;
    _2 = (int)SEQ_PTR(_4656);
    _4656 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_4656);
    DeRefDS(_0);
    { int _i;
        _i = 1;
L1B:
        if (binary_op_a(GREATER, _i, _4656))
            goto L1C;

        // 		    SymTab[p][S_ARG_SEQ_ELEM_NEW] = TYPE_OBJECT
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
        _2 = (int)(((s1_ptr)_2)->base + 43);
        _1 = *(int *)_2;
        *(int *)_2 = 16;
        DeRef(_1);

        // 		    SymTab[p][S_ARG_TYPE_NEW] = TYPE_OBJECT
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
        _2 = (int)(((s1_ptr)_2)->base + 41);
        _1 = *(int *)_2;
        *(int *)_2 = 16;
        DeRef(_1);

        // 		    SymTab[p][S_ARG_MIN_NEW] = NOVALUE
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
        _2 = (int)(((s1_ptr)_2)->base + 46);
        _1 = *(int *)_2;
        *(int *)_2 = _4NOVALUE;
        DeRef(_1);

        // 		    SymTab[p][S_ARG_SEQ_LEN_NEW] = NOVALUE
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
        _2 = (int)(((s1_ptr)_2)->base + 49);
        _1 = *(int *)_2;
        *(int *)_2 = _4NOVALUE;
        DeRef(_1);

        // 		    p = SymTab[p][S_NEXT]
        DeRef(_4658);
        _2 = (int)SEQ_PTR(_4SymTab);
        _4658 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_4658);
        _2 = (int)SEQ_PTR(_4658);
        _p = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_p))
            _p = (long)DBL_PTR(_p)->dbl;

        // 		end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef(_0);
        goto L1B;
L1C:
        ;
        DeRef(_i);
    }
L10:

    // 	    seq_num += 1
    _seq_num = _seq_num + 1;
LF:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4658);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4658 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4658);
    _2 = (int)SEQ_PTR(_4658);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto LD;
LE:

    //     if not first then
    if (_first != 0)
        goto L1D;

    // 	c_puts(",\n")
    RefDS(_4692);
    _9c_puts(_4692);
L1D:

    //     c_puts("  {\"\", 0, 999999999, 0, 0, 0}\n};\n\n")  -- end marker
    RefDS(_4743);
    _9c_puts(_4743);

    // end procedure   
    DeRef(_4658);
    DeRef(_4650);
    DeRef(_4656);
    return 0;
    ;
}


int _16DeclareNameSpaceList()
{
    int _s;
    int _first;
    int _seq_num;
    int _4750 = 0;
    int _4746 = 0;
    int _0, _1, _2;
    

    //     c_hputs("extern struct ns_list _01[];\n")
    RefDS(_4744);
    _9c_hputs(_4744);

    //     c_puts("struct ns_list _01[] = {\n")
    RefDS(_4745);
    _9c_puts(_4745);

    //     seq_num = 0
    _seq_num = 0;

    //     first = TRUE
    _first = 1;

    //     s = SymTab[TopLevelSub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4746 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4746);
    _2 = (int)SEQ_PTR(_4746);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
L1:
    if (_s == 0)
        goto L2;

    // 	if find(SymTab[s][S_TOKEN], {PROC, FUNC, TYPE, NAMESPACE}) then
    DeRef(_4746);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4746 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4746);
    _0 = _4746;
    _2 = (int)SEQ_PTR(_4746);
    _4746 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4746);
    DeRefDS(_0);
    _0 = _4750;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 523;
    _4750 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4750;
    _4750 = find(_4746, _4750);
    DeRefDSi(_0);
    if (_4750 == 0)
        goto L3;

    // 	    if SymTab[s][S_TOKEN] = NAMESPACE then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4750 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4750);
    _0 = _4750;
    _2 = (int)SEQ_PTR(_4750);
    _4750 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4750);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4750, 523))
        goto L4;

    // 		if not first then
    if (_first != 0)
        goto L5;

    // 		    c_puts(",\n")
    RefDS(_4692);
    _9c_puts(_4692);
L5:

    // 		first = FALSE
    _first = 0;

    // 		c_puts("  {\"")
    RefDS(_4693);
    _9c_puts(_4693);

    // 		c_puts(SymTab[s][S_NAME])
    DeRef(_4750);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4750 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4750);
    _0 = _4750;
    _2 = (int)SEQ_PTR(_4750);
    _4750 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4750);
    DeRefDS(_0);
    Ref(_4750);
    _9c_puts(_4750);

    // 		c_printf("\", %d", SymTab[s][S_OBJ])
    DeRef(_4750);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4750 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4750);
    _0 = _4750;
    _2 = (int)SEQ_PTR(_4750);
    _4750 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4750);
    DeRefDS(_0);
    RefDS(_4758);
    Ref(_4750);
    _9c_printf(_4758, _4750);

    // 		c_printf(", %d", seq_num)
    RefDS(_4702);
    _9c_printf(_4702, _seq_num);

    // 		c_printf(", %d", SymTab[s][S_FILE_NO])
    DeRef(_4750);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4750 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4750);
    _0 = _4750;
    _2 = (int)SEQ_PTR(_4750);
    _4750 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4750);
    DeRefDS(_0);
    RefDS(_4702);
    Ref(_4750);
    _9c_printf(_4702, _4750);

    // 		c_puts("}")
    RefDS(_34);
    _9c_puts(_34);
L4:

    // 	    seq_num += 1
    _seq_num = _seq_num + 1;
L3:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4750);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4750 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4750);
    _2 = (int)SEQ_PTR(_4750);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    //     if not first then
    if (_first != 0)
        goto L6;

    // 	c_puts(",\n")
    RefDS(_4692);
    _9c_puts(_4692);
L6:

    //     c_puts("  {\"\", 0, 999999999, 0}\n};\n\n")  -- end marker
    RefDS(_4767);
    _9c_puts(_4767);

    // end procedure
    DeRef(_4750);
    DeRef(_4746);
    return 0;
    ;
}


int _16Write_def_file(int _def_file)
{
    int _s;
    int _4768 = 0;
    int _4774 = 0;
    int _4796 = 0;
    int _4785 = 0;
    int _0, _1, _2;
    

    //     if atom(wat_path) then
    _4768 = IS_ATOM(_4wat_path);
    if (_4768 == 0)
        goto L1;

    // 	puts(def_file, "EXPORTS\n")
    EPuts(_def_file, _4769);
L1:

    //     s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_4768);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4768 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4768);
    _2 = (int)SEQ_PTR(_4768);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
L2:
    if (_s == 0)
        goto L3;

    // 	if find(SymTab[s][S_TOKEN], {PROC, FUNC, TYPE}) then
    DeRef(_4768);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4768 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4768);
    _0 = _4768;
    _2 = (int)SEQ_PTR(_4768);
    _4768 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4768);
    DeRefDS(_0);
    _0 = _4774;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _4774 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4774;
    _4774 = find(_4768, _4774);
    DeRefDSi(_0);
    if (_4774 == 0)
        goto L4;

    // 	    if SymTab[s][S_SCOPE] = SC_GLOBAL then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4774 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4774);
    _0 = _4774;
    _2 = (int)SEQ_PTR(_4774);
    _4774 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4774);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4774, 6))
        goto L5;

    // 		if sequence(bor_path) then             
    DeRef(_4774);
    _4774 = IS_SEQUENCE(_4bor_path);
    if (_4774 == 0)
        goto L6;

    // 		    printf(def_file, "%s=_%d%s\n", 
    _2 = (int)SEQ_PTR(_4SymTab);
    _4774 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4774);
    _0 = _4774;
    _2 = (int)SEQ_PTR(_4774);
    _4774 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4774);
    DeRefDS(_0);
    DeRef(_4768);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4768 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4768);
    _0 = _4768;
    _2 = (int)SEQ_PTR(_4768);
    _4768 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4768);
    DeRefDS(_0);
    DeRef(_4785);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4785 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4785);
    _0 = _4785;
    _2 = (int)SEQ_PTR(_4785);
    _4785 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4785);
    DeRefDS(_0);
    _0 = _4785;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4774);
    *((int *)(_2+4)) = _4774;
    Ref(_4768);
    *((int *)(_2+8)) = _4768;
    Ref(_4785);
    *((int *)(_2+12)) = _4785;
    _4785 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_def_file, _4780, _4785);
    goto L7;
L6:

    // 		elsif sequence(wat_path) then
    DeRef(_4785);
    _4785 = IS_SEQUENCE(_4wat_path);
    if (_4785 == 0)
        goto L8;

    // 		    printf(def_file, "EXPORT %s='__%d%s@%d'\n", 
    _2 = (int)SEQ_PTR(_4SymTab);
    _4785 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4785);
    _0 = _4785;
    _2 = (int)SEQ_PTR(_4785);
    _4785 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4785);
    DeRefDS(_0);
    DeRef(_4768);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4768 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4768);
    _0 = _4768;
    _2 = (int)SEQ_PTR(_4768);
    _4768 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4768);
    DeRefDS(_0);
    DeRef(_4774);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4774 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4774);
    _0 = _4774;
    _2 = (int)SEQ_PTR(_4774);
    _4774 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4774);
    DeRefDS(_0);
    DeRef(_4796);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4796 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4796);
    _0 = _4796;
    _2 = (int)SEQ_PTR(_4796);
    _4796 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_4796);
    DeRefDS(_0);
    _0 = _4796;
    if (IS_ATOM_INT(_4796)) {
        if (_4796 == (short)_4796)
            _4796 = _4796 * 4;
        else
            _4796 = NewDouble(_4796 * (double)4);
    }
    else {
        _4796 = binary_op(MULTIPLY, _4796, 4);
    }
    DeRef(_0);
    _0 = _4796;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4785);
    *((int *)(_2+4)) = _4785;
    Ref(_4768);
    *((int *)(_2+8)) = _4768;
    Ref(_4774);
    *((int *)(_2+12)) = _4774;
    Ref(_4796);
    *((int *)(_2+16)) = _4796;
    _4796 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_def_file, _4789, _4796);
    goto L7;
L8:

    // 		    printf(def_file, "_%d%s@%d\n", 
    DeRef(_4796);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4796 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4796);
    _0 = _4796;
    _2 = (int)SEQ_PTR(_4796);
    _4796 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4796);
    DeRefDS(_0);
    DeRef(_4774);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4774 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4774);
    _0 = _4774;
    _2 = (int)SEQ_PTR(_4774);
    _4774 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4774);
    DeRefDS(_0);
    DeRef(_4768);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4768 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4768);
    _0 = _4768;
    _2 = (int)SEQ_PTR(_4768);
    _4768 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_4768);
    DeRefDS(_0);
    _0 = _4768;
    if (IS_ATOM_INT(_4768)) {
        if (_4768 == (short)_4768)
            _4768 = _4768 * 4;
        else
            _4768 = NewDouble(_4768 * (double)4);
    }
    else {
        _4768 = binary_op(MULTIPLY, _4768, 4);
    }
    DeRef(_0);
    _0 = _4768;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4796);
    *((int *)(_2+4)) = _4796;
    Ref(_4774);
    *((int *)(_2+8)) = _4774;
    Ref(_4768);
    *((int *)(_2+12)) = _4768;
    _4768 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_def_file, _4800, _4768);
L7:
L5:
L4:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4768);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4768 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4768);
    _2 = (int)SEQ_PTR(_4768);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L2;
L3:

    // end procedure
    DeRef(_4768);
    DeRef(_4774);
    DeRef(_4796);
    DeRef(_4785);
    return 0;
    ;
}


