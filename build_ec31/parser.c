// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _15EndLineTable()
{
    int _0, _1, _2;
    

    //     LineTable = append(LineTable, -2)
    Append(&_4LineTable, _4LineTable, -2);

    // end procedure
    return 0;
    ;
}


int _15CreateTopLevel()
{
    int _0, _1, _2, _3;
    

    //     SymTab[TopLevelSub][S_NUM_ARGS] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 20);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_TEMPS] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_CODE] = {}
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_LINETAB] = {}
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_FIRSTLINE] = 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 17);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_REFLIST] = {}
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
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

    //     SymTab[TopLevelSub][S_NREFS] = 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_RESIDENT_TASK] = 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_SAVED_PRIVATES] = {}
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    // end procedure
    return 0;
    ;
}


int _15EnterTopLevel()
{
    int _2981 = 0;
    int _0, _1, _2, _3;
    

    //     if CurrentSub then
    if (_4CurrentSub == 0)
        goto L1;

    // 	EndLineTable()
    _15EndLineTable();

    // 	SymTab[CurrentSub][S_LINETAB] = LineTable
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    RefDS(_4LineTable);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _4LineTable;
    DeRef(_1);

    // 	SymTab[CurrentSub][S_CODE] = Code
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    RefDS(_4Code);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _4Code;
    DeRef(_1);
L1:

    //     LineTable = SymTab[TopLevelSub][S_LINETAB]
    DeRef(_2981);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2981 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_2981);
    DeRef(_4LineTable);
    _2 = (int)SEQ_PTR(_2981);
    _4LineTable = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_4LineTable);

    //     Code = SymTab[TopLevelSub][S_CODE]
    DeRefDS(_2981);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2981 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_2981);
    DeRef(_4Code);
    _2 = (int)SEQ_PTR(_2981);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    //     previous_op = -1
    _14previous_op = -1;

    //     CurrentSub = TopLevelSub
    _4CurrentSub = _4TopLevelSub;

    // end procedure
    DeRefDS(_2981);
    return 0;
    ;
}


int _15LeaveTopLevel()
{
    int _0, _1, _2, _3;
    

    //     LastLineNumber = -1
    _11LastLineNumber = -1;

    //     SymTab[TopLevelSub][S_LINETAB] = LineTable
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_4LineTable);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _4LineTable;
    DeRef(_1);

    //     SymTab[TopLevelSub][S_CODE] = Code
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4TopLevelSub + ((s1_ptr)_2)->base);
    RefDS(_4Code);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _4Code;
    DeRef(_1);

    //     LineTable = {}
    RefDS(_39);
    DeRefDS(_4LineTable);
    _4LineTable = _39;

    //     Code = {}
    RefDS(_39);
    DeRefDS(_4Code);
    _4Code = _39;

    //     previous_op = -1
    _14previous_op = -1;

    // end procedure
    return 0;
    ;
}


int _15InitParser()
{
    int _0, _1, _2;
    

    //     elist = {}
    RefDS(_39);
    DeRefi(_15elist);
    _15elist = _39;

    //     exit_list = {}
    RefDS(_39);
    DeRefi(_15exit_list);
    _15exit_list = _39;

    //     init_stack = {}
    RefDS(_39);
    DeRefi(_15init_stack);
    _15init_stack = _39;

    //     CurrentSub = 0
    _4CurrentSub = 0;

    //     CreateTopLevel()
    _15CreateTopLevel();

    //     EnterTopLevel()
    _15EnterTopLevel();

    //     backed_up_tok = UNDEFINED
    DeRef(_15backed_up_tok);
    _15backed_up_tok = -999;

    //     loop_nest = 0
    _15loop_nest = 0;

    //     stmt_nest = 0
    _15stmt_nest = 0;

    // end procedure
    return 0;
    ;
}


int _15NotReached(int _tok, int _keyword)
{
    int _2993 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_tok)) {
        _1 = (long)(DBL_PTR(_tok)->dbl);
        DeRefDS(_tok);
        _tok = _1;
    }

    //     if not find(tok, {END, ELSE, ELSIF, END_OF_FILE}) then
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 402;
    *((int *)(_2+8)) = 23;
    *((int *)(_2+12)) = 413;
    *((int *)(_2+16)) = -21;
    _2993 = MAKE_SEQ(_1);
    _0 = _2993;
    _2993 = find(_tok, _2993);
    DeRefDSi(_0);
    if (_2993 != 0)
        goto L1;

    // 	Warning(sprintf("%s:%d - statement after %s will never be executed", 
    _2 = (int)SEQ_PTR(_4file_name);
    _2993 = (int)*(((s1_ptr)_2)->base + _4current_file_no);
    RefDS(_2993);
    RefDS(_2993);
    _0 = _2993;
    _2993 = _10name_ext(_2993);
    DeRefDS(_0);
    _0 = _2993;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_2993);
    *((int *)(_2+4)) = _2993;
    *((int *)(_2+8)) = _4line_number;
    RefDS(_keyword);
    *((int *)(_2+12)) = _keyword;
    _2993 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _2993;
    _2993 = EPrintf(-9999999, _2996, _2993);
    DeRefDS(_0);
    RefDS(_2993);
    _6Warning(_2993);
L1:

    // end procedure
    DeRefDSi(_keyword);
    DeRef(_2993);
    return 0;
    ;
}


int _15InitCheck(int _sym, int _ref)
{
    int _3024 = 0;
    int _3026 = 0;
    int _3001 = 0;
    int _3005 = 0;
    int _0, _1, _2, _3;
    

    //     if SymTab[sym][S_MODE] = M_NORMAL and 
    _2 = (int)SEQ_PTR(_4SymTab);
    _3001 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3001);
    _0 = _3001;
    _2 = (int)SEQ_PTR(_3001);
    _3001 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3001);
    DeRefDS(_0);
    _0 = _3001;
    if (IS_ATOM_INT(_3001)) {
        _3001 = (_3001 == 1);
    }
    else {
        _3001 = binary_op(EQUALS, _3001, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3001)) {
        if (_3001 == 0) {
            DeRef(_3001);
            _3001 = 0;
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_3001)->dbl == 0.0) {
            DeRef(_3001);
            _3001 = 0;
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_4SymTab);
    _3005 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3005);
    _0 = _3005;
    _2 = (int)SEQ_PTR(_3005);
    _3005 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3005);
    DeRefDS(_0);
    _0 = _3005;
    if (IS_ATOM_INT(_3005)) {
        _3005 = (_3005 != 2);
    }
    else {
        _3005 = binary_op(NOTEQ, _3005, 2);
    }
    DeRef(_0);
    DeRef(_3001);
    if (IS_ATOM_INT(_3005))
        _3001 = (_3005 != 0);
    else
        _3001 = DBL_PTR(_3005)->dbl != 0.0;
L1:
    if (_3001 == 0) {
        goto L2;
    }
    DeRef(_3001);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3001 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3001);
    _0 = _3001;
    _2 = (int)SEQ_PTR(_3001);
    _3001 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3001);
    DeRefDS(_0);
    _0 = _3001;
    if (IS_ATOM_INT(_3001)) {
        _3001 = (_3001 != 4);
    }
    else {
        _3001 = binary_op(NOTEQ, _3001, 4);
    }
    DeRef(_0);
L3:
    if (_3001 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_3001) && DBL_PTR(_3001)->dbl == 0.0)
            goto L2;
    }

    // 	if (SymTab[sym][S_SCOPE] != SC_PRIVATE and 
    DeRef(_3001);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3001 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3001);
    _0 = _3001;
    _2 = (int)SEQ_PTR(_3001);
    _3001 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3001);
    DeRefDS(_0);
    _0 = _3001;
    if (IS_ATOM_INT(_3001)) {
        _3001 = (_3001 != 3);
    }
    else {
        _3001 = binary_op(NOTEQ, _3001, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3001)) {
        if (_3001 == 0) {
            DeRef(_3001);
            _3001 = 0;
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_3001)->dbl == 0.0) {
            DeRef(_3001);
            _3001 = 0;
            goto L4;
        }
    }
    DeRef(_3005);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3005 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3005);
    _0 = _3005;
    _2 = (int)SEQ_PTR(_3005);
    _3005 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3005);
    DeRefDS(_0);
    _0 = _3005;
    if (_3005 == _4NOVALUE)
        _3005 = 1;
    else if (IS_ATOM_INT(_3005) && IS_ATOM_INT(_4NOVALUE))
        _3005 = 0;
    else
        _3005 = (compare(_3005, _4NOVALUE) == 0);
    DeRef(_0);
    DeRef(_3001);
    _3001 = (_3005 != 0);
L4:
    if (_3001 != 0) {
        goto L5;
    }
    DeRef(_3001);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3001 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3001);
    _0 = _3001;
    _2 = (int)SEQ_PTR(_3001);
    _3001 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3001);
    DeRefDS(_0);
    _0 = _3001;
    if (IS_ATOM_INT(_3001)) {
        _3001 = (_3001 == 3);
    }
    else {
        _3001 = binary_op(EQUALS, _3001, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3001)) {
        if (_3001 == 0) {
            DeRef(_3001);
            _3001 = 0;
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_3001)->dbl == 0.0) {
            DeRef(_3001);
            _3001 = 0;
            goto L6;
        }
    }
    DeRef(_3024);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3024 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3024);
    _0 = _3024;
    _2 = (int)SEQ_PTR(_3024);
    _3024 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_3024);
    DeRefDS(_0);
    DeRef(_3026);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3026 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_3026);
    _0 = _3026;
    _2 = (int)SEQ_PTR(_3026);
    _3026 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3026);
    DeRefDS(_0);
    _0 = _3026;
    if (IS_ATOM_INT(_3024) && IS_ATOM_INT(_3026)) {
        _3026 = (_3024 >= _3026);
    }
    else {
        _3026 = binary_op(GREATEREQ, _3024, _3026);
    }
    DeRef(_0);
    DeRef(_3001);
    if (IS_ATOM_INT(_3026))
        _3001 = (_3026 != 0);
    else
        _3001 = DBL_PTR(_3026)->dbl != 0.0;
L6:
L7:
    if (_3001 == 0)
        goto L8;
L5:

    // 	    if SymTab[sym][S_INITLEVEL] = -1 then
    DeRef(_3026);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3026 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3026);
    _0 = _3026;
    _2 = (int)SEQ_PTR(_3026);
    _3026 = (int)*(((s1_ptr)_2)->base + 13);
    Ref(_3026);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3026, -1))
        goto L9;

    // 		if ref then
    if (_ref == 0)
        goto LA;

    // 		    if SymTab[sym][S_SCOPE] = SC_GLOBAL or 
    DeRef(_3026);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3026 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3026);
    _0 = _3026;
    _2 = (int)SEQ_PTR(_3026);
    _3026 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3026);
    DeRefDS(_0);
    _0 = _3026;
    if (IS_ATOM_INT(_3026)) {
        _3026 = (_3026 == 6);
    }
    else {
        _3026 = binary_op(EQUALS, _3026, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3026)) {
        if (_3026 != 0) {
            goto LB;
        }
    }
    else {
        if (DBL_PTR(_3026)->dbl != 0.0) {
            goto LB;
        }
    }
    DeRef(_3024);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3024 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3024);
    _0 = _3024;
    _2 = (int)SEQ_PTR(_3024);
    _3024 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3024);
    DeRefDS(_0);
    _0 = _3024;
    if (IS_ATOM_INT(_3024)) {
        _3024 = (_3024 == 5);
    }
    else {
        _3024 = binary_op(EQUALS, _3024, 5);
    }
    DeRef(_0);
LC:
    if (_3024 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_3024) && DBL_PTR(_3024)->dbl == 0.0)
            goto LD;
    }
LB:

    // 			emit_op(GLOBAL_INIT_CHECK) -- will become NOP2
    _14emit_op(109);
    goto LE;
LD:

    // 			emit_op(PRIVATE_INIT_CHECK)
    _14emit_op(30);
LE:

    // 		    emit_addr(sym)
    _14emit_addr(_sym);
LA:

    // 		if short_circuit <= 0 or short_circuit_B = FALSE then
    DeRef(_3024);
    _3024 = (_15short_circuit <= 0);
    if (_3024 != 0) {
        goto LF;
    }
    DeRef(_3026);
    _3026 = (_15short_circuit_B == 0);
L10:
    if (_3026 == 0)
        goto L11;
LF:

    // 		    init_stack = append(init_stack, sym)
    Append(&_15init_stack, _15init_stack, _sym);

    // 		    SymTab[sym][S_INITLEVEL] = stmt_nest
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 13);
    _1 = *(int *)_2;
    *(int *)_2 = _15stmt_nest;
    DeRef(_1);
L11:
L9:
L8:
L2:

    // end procedure
    DeRef(_3024);
    DeRef(_3026);
    DeRef(_3001);
    DeRef(_3005);
    return 0;
    ;
}


int _15InitDelete()
{
    int _3045;
    int _3047 = 0;
    int _0, _1, _2, _3;
    

    //     while length(init_stack) and 
L1:
    _3045 = SEQ_PTR(_15init_stack)->length;
    if (_3045 == 0) {
        goto L2;
    }
    DeRef(_3047);
    _3047 = SEQ_PTR(_15init_stack)->length;
    _2 = (int)SEQ_PTR(_15init_stack);
    _3047 = (int)*(((s1_ptr)_2)->base + _3047);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3047 = (int)*(((s1_ptr)_2)->base + _3047);
    RefDS(_3047);
    _0 = _3047;
    _2 = (int)SEQ_PTR(_3047);
    _3047 = (int)*(((s1_ptr)_2)->base + 13);
    Ref(_3047);
    DeRefDS(_0);
    _0 = _3047;
    if (IS_ATOM_INT(_3047)) {
        _3047 = (_3047 > _15stmt_nest);
    }
    else {
        _3047 = binary_op(GREATER, _3047, _15stmt_nest);
    }
    DeRef(_0);
L3:
    if (_3047 <= 0) {
        if (_3047 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_3047) && DBL_PTR(_3047)->dbl == 0.0)
                goto L2;
        }
    }

    // 	SymTab[init_stack[$]][S_INITLEVEL] = -1
    DeRef(_3047);
    _3047 = SEQ_PTR(_15init_stack)->length;
    _2 = (int)SEQ_PTR(_15init_stack);
    _3047 = (int)*(((s1_ptr)_2)->base + _3047);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_3047 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 13);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	init_stack = init_stack[1..$-1]
    _3045 = SEQ_PTR(_15init_stack)->length;
    _3045 = _3045 - 1;
    rhs_slice_target = (object_ptr)&_15init_stack;
    RHS_Slice((s1_ptr)_15init_stack, 1, _3045);

    //     end while
    goto L1;
L2:

    // end procedure
    DeRef(_3047);
    return 0;
    ;
}


int _15emit_forward_addr()
{
    int _3059;
    int _0, _1, _2;
    

    //     emit_addr(0)
    _14emit_addr(0);

    //     branch_list = append(branch_list, length(Code))
    _3059 = SEQ_PTR(_4Code)->length;
    Append(&_15branch_list, _15branch_list, _3059);

    // end procedure
    return 0;
    ;
}


int _15StraightenBranches()
{
    int _br;
    int _target;
    int _3069 = 0;
    int _3061;
    int _0, _1, _2;
    

    //     if TRANSLATE then

    // 	return -- do it in back-end
    return 0;
L1:

    //     for i = length(branch_list) to 1 by -1 do
    _3061 = SEQ_PTR(_15branch_list)->length;
    { int _i;
        _i = _3061;
L2:
        if (_i < 1)
            goto L3;

        // 	target = Code[branch_list[i]]
        _2 = (int)SEQ_PTR(_15branch_list);
        _3061 = (int)*(((s1_ptr)_2)->base + _i);
        _2 = (int)SEQ_PTR(_4Code);
        _target = (int)*(((s1_ptr)_2)->base + _3061);
        if (!IS_ATOM_INT(_target))
            _target = (long)DBL_PTR(_target)->dbl;

        // 	if target <= length(Code) then
        _3061 = SEQ_PTR(_4Code)->length;
        if (_target > _3061)
            goto L4;

        // 	    br = Code[target]
        _2 = (int)SEQ_PTR(_4Code);
        _br = (int)*(((s1_ptr)_2)->base + _target);
        if (!IS_ATOM_INT(_br))
            _br = (long)DBL_PTR(_br)->dbl;

        // 	    if br = ELSE or br = ENDWHILE or br = EXIT then
        _3061 = (_br == 23);
        if (_3061 != 0) {
            _3061 = 1;
            goto L5;
        }
        DeRef(_3069);
        _3069 = (_br == 22);
        _3061 = (_3069 != 0);
L5:
        if (_3061 != 0) {
            goto L6;
        }
        _3061 = (_br == 61);
L7:
        if (_3061 == 0)
            goto L8;
L6:

        // 		backpatch(branch_list[i], Code[target+1])
        _2 = (int)SEQ_PTR(_15branch_list);
        _3061 = (int)*(((s1_ptr)_2)->base + _i);
        DeRef(_3069);
        _3069 = _target + 1;
        _2 = (int)SEQ_PTR(_4Code);
        _3069 = (int)*(((s1_ptr)_2)->base + _3069);
        Ref(_3069);
        Ref(_3069);
        _14backpatch(_3061, _3069);
L8:
L4:

        //     end for
        _i = _i + -1;
        goto L2;
L3:
        ;
    }

    //     branch_list = {}
    RefDS(_39);
    DeRefi(_15branch_list);
    _15branch_list = _39;

    // end procedure
    DeRef(_3069);
    return 0;
    ;
}


int _15AppendEList(int _addr)
{
    int _0, _1, _2;
    

    //     elist = append(elist, addr)
    Append(&_15elist, _15elist, _addr);

    // end procedure
    return 0;
    ;
}


int _15AppendXList(int _addr)
{
    int _0, _1, _2;
    

    //     exit_list = append(exit_list, addr)
    Append(&_15exit_list, _15exit_list, _addr);

    // end procedure
    return 0;
    ;
}


int _15PatchEList(int _base)
{
    int _elist_top;
    int _3080;
    int _3077;
    int _0, _1, _2;
    

    //     elist_top = length(elist)
    _elist_top = SEQ_PTR(_15elist)->length;

    //     while elist_top > base do
L1:
    if (_elist_top <= _base)
        goto L2;

    // 	backpatch(elist[elist_top], length(Code)+1)
    _2 = (int)SEQ_PTR(_15elist);
    _3077 = (int)*(((s1_ptr)_2)->base + _elist_top);
    _3080 = SEQ_PTR(_4Code)->length;
    _3080 = _3080 + 1;
    _14backpatch(_3077, _3080);

    // 	elist_top -= 1
    _elist_top = _elist_top - 1;

    //     end while
    goto L1;
L2:

    //     elist = elist[1..base]
    rhs_slice_target = (object_ptr)&_15elist;
    RHS_Slice((s1_ptr)_15elist, 1, _base);

    // end procedure
    return 0;
    ;
}


int _15PatchXList(int _base)
{
    int _exit_top;
    int _3087;
    int _3084;
    int _0, _1, _2;
    

    //     exit_top = length(exit_list)
    _exit_top = SEQ_PTR(_15exit_list)->length;

    //     while exit_top > base do
L1:
    if (_exit_top <= _base)
        goto L2;

    // 	backpatch(exit_list[exit_top], length(Code)+1)
    _2 = (int)SEQ_PTR(_15exit_list);
    _3084 = (int)*(((s1_ptr)_2)->base + _exit_top);
    _3087 = SEQ_PTR(_4Code)->length;
    _3087 = _3087 + 1;
    _14backpatch(_3084, _3087);

    // 	exit_top -= 1
    _exit_top = _exit_top - 1;

    //     end while
    goto L1;
L2:

    //     exit_list = exit_list[1..base] 
    rhs_slice_target = (object_ptr)&_15exit_list;
    RHS_Slice((s1_ptr)_15exit_list, 1, _base);

    // end procedure
    return 0;
    ;
}


int _15putback(int _t)
{
    int _0, _1, _2;
    

    //     backed_up_tok = t
    RefDS(_t);
    DeRef(_15backed_up_tok);
    _15backed_up_tok = _t;

    // end procedure
    DeRefDS(_t);
    return 0;
    ;
}


int _15next_token()
{
    int _t = 0;
    int _3091;
    int _0, _1, _2;
    

    //     if atom(backed_up_tok) then
    _3091 = IS_ATOM(_15backed_up_tok);
    if (_3091 == 0)
        goto L1;

    // 	 t = Scanner() 
    _t = _11Scanner();
    goto L2;
L1:

    // 	 t = backed_up_tok 
    Ref(_15backed_up_tok);
    DeRef(_t);
    _t = _15backed_up_tok;

    // 	 backed_up_tok = UNDEFINED 
    DeRef(_15backed_up_tok);
    _15backed_up_tok = -999;
L2:

    //     return t
    return _t;
    ;
}


int _15Expr_list()
{
    int _tok = 0;
    int _n;
    int _3093 = 0;
    int _0, _1, _2;
    

    //     tok = next_token()
    _tok = _15next_token();

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    //     if tok[T_ID] = RIGHT_BRACE then
    _2 = (int)SEQ_PTR(_tok);
    _3093 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3093);
    if (binary_op_a(NOTEQ, _3093, -25))
        goto L1;

    // 	return 0
    DeRefDS(_tok);
    DeRef(_3093);
    return 0;
    goto L2;
L1:

    // 	n = 0
    _n = 0;

    // 	short_circuit -= 1
    _15short_circuit = _15short_circuit - 1;

    // 	while TRUE do 
L3:

    // 	    call_proc(forward_expr, {})
    _0 = (int)_00[_15forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 	    n += 1
    _n = _n + 1;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	    if tok[T_ID] != COMMA then
    DeRef(_3093);
    _2 = (int)SEQ_PTR(_tok);
    _3093 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3093);
    if (binary_op_a(EQUALS, _3093, -30))
        goto L3;

    // 		exit
    goto L4;
L5:

    // 	end while  
    goto L3;
L4:

    // 	short_circuit += 1
    _15short_circuit = _15short_circuit + 1;
L2:

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    //     return n
    DeRefDS(_tok);
    DeRef(_3093);
    return _n;
    ;
}


int _15tok_match(int _tok)
{
    int _t = 0;
    int _expected = 0;
    int _actual = 0;
    int _3102 = 0;
    int _0, _1, _2;
    

    //     t = next_token()
    _t = _15next_token();

    //     if t[T_ID] != tok then
    _2 = (int)SEQ_PTR(_t);
    _3102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3102);
    if (binary_op_a(EQUALS, _3102, _tok))
        goto L1;

    // 	expected = LexName(tok)
    _expected = _14LexName(_tok);

    // 	actual = LexName(t[T_ID])
    DeRef(_3102);
    _2 = (int)SEQ_PTR(_t);
    _3102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3102);
    Ref(_3102);
    _actual = _14LexName(_3102);

    // 	CompileErr(sprintf(
    DeRef(_3102);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _expected;
    RefDS(_expected);
    ((int *)_2)[2] = _actual;
    RefDS(_actual);
    _3102 = MAKE_SEQ(_1);
    _0 = _3102;
    _3102 = EPrintf(-9999999, _3108, _3102);
    DeRefDS(_0);
    RefDS(_3102);
    _6CompileErr(_3102);
L1:

    // end procedure
    DeRef(_t);
    DeRef(_expected);
    DeRef(_actual);
    DeRef(_3102);
    return 0;
    ;
}


int _15UndefinedVar(int _s)
{
    int _dup;
    int _errmsg = 0;
    int _3125 = 0;
    int _3111 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     if SymTab[s][S_SCOPE] = SC_UNDEFINED then
    _2 = (int)SEQ_PTR(_4SymTab);
    _3111 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3111);
    _0 = _3111;
    _2 = (int)SEQ_PTR(_3111);
    _3111 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3111);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3111, 9))
        goto L1;

    // 	CompileErr(sprintf("%s has not been declared", {SymTab[s][S_NAME]}))
    DeRef(_3111);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3111 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3111);
    _0 = _3111;
    _2 = (int)SEQ_PTR(_3111);
    _3111 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3111);
    DeRefDS(_0);
    _0 = _3111;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3111);
    *((int *)(_2+4)) = _3111;
    _3111 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3111;
    _3111 = EPrintf(-9999999, _3114, _3111);
    DeRefDS(_0);
    RefDS(_3111);
    _6CompileErr(_3111);
    goto L2;
L1:

    //     elsif SymTab[s][S_SCOPE] = SC_MULTIPLY_DEFINED then
    DeRef(_3111);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3111 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3111);
    _0 = _3111;
    _2 = (int)SEQ_PTR(_3111);
    _3111 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3111);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3111, 10))
        goto L3;

    // 	errmsg = sprintf("A namespace qualifier is needed to resolve %s.\n%s is defined as a global symbol in:\n", 
    DeRef(_3111);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3111 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3111);
    _0 = _3111;
    _2 = (int)SEQ_PTR(_3111);
    _3111 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3111);
    DeRefDS(_0);
    DeRef(_3125);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3125 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3125);
    _0 = _3125;
    _2 = (int)SEQ_PTR(_3125);
    _3125 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3125);
    DeRefDS(_0);
    _0 = _3125;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _3111;
    Ref(_3111);
    ((int *)_2)[2] = _3125;
    Ref(_3125);
    _3125 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_errmsg);
    _errmsg = EPrintf(-9999999, _3122, _3125);

    // 	for i = length(dup_globals) to 1 by -1 do
    DeRefDS(_3125);
    _3125 = SEQ_PTR(_10dup_globals)->length;
    { int _i;
        _i = _3125;
L4:
        if (_i < 1)
            goto L5;

        // 	    dup = dup_globals[i]
        _2 = (int)SEQ_PTR(_10dup_globals);
        _dup = (int)*(((s1_ptr)_2)->base + _i);

        // 	    errmsg &= "    " & file_name[SymTab[dup][S_FILE_NO]] & "\n"
        DeRef(_3125);
        _2 = (int)SEQ_PTR(_4SymTab);
        _3125 = (int)*(((s1_ptr)_2)->base + _dup);
        RefDS(_3125);
        _0 = _3125;
        _2 = (int)SEQ_PTR(_3125);
        _3125 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_3125);
        DeRefDS(_0);
        _0 = _3125;
        _2 = (int)SEQ_PTR(_4file_name);
        if (!IS_ATOM_INT(_3125))
            _3125 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3125)->dbl));
        else
            _3125 = (int)*(((s1_ptr)_2)->base + _3125);
        RefDS(_3125);
        DeRef(_0);
        {
            int concat_list[3];

            concat_list[0] = _629;
            concat_list[1] = _3125;
            concat_list[2] = _913;
            Concat_N((object_ptr)&_3125, concat_list, 3);
        }
        Concat((object_ptr)&_errmsg, _errmsg, (s1_ptr)_3125);

        // 	end for
        _i = _i + -1;
        goto L4;
L5:
        ;
    }

    // 	CompileErr(errmsg)
    RefDS(_errmsg);
    _6CompileErr(_errmsg);
L3:
L2:

    // end procedure
    DeRef(_errmsg);
    DeRef(_3125);
    DeRef(_3111);
    return 0;
    ;
}


int _15WrongNumberArgs(int _subsym, int _only)
{
    int _plural = 0;
    int _3143 = 0;
    int _3136 = 0;
    int _0, _1, _2;
    

    //     if SymTab[subsym][S_NUM_ARGS] = 1 then
    _2 = (int)SEQ_PTR(_4SymTab);
    _3136 = (int)*(((s1_ptr)_2)->base + _subsym);
    RefDS(_3136);
    _0 = _3136;
    _2 = (int)SEQ_PTR(_3136);
    _3136 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3136);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3136, 1))
        goto L1;

    // 	plural = ""
    RefDS(_39);
    _plural = _39;
    goto L2;
L1:

    // 	plural = "s"
    RefDS(_3139);
    DeRefi(_plural);
    _plural = _3139;
L2:

    //     CompileErr(sprintf("%s takes %s%d argument%s", 
    DeRef(_3136);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3136 = (int)*(((s1_ptr)_2)->base + _subsym);
    RefDS(_3136);
    _0 = _3136;
    _2 = (int)SEQ_PTR(_3136);
    _3136 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3136);
    DeRefDS(_0);
    DeRef(_3143);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3143 = (int)*(((s1_ptr)_2)->base + _subsym);
    RefDS(_3143);
    _0 = _3143;
    _2 = (int)SEQ_PTR(_3143);
    _3143 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3143);
    DeRefDS(_0);
    _0 = _3143;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3136);
    *((int *)(_2+4)) = _3136;
    RefDS(_only);
    *((int *)(_2+8)) = _only;
    Ref(_3143);
    *((int *)(_2+12)) = _3143;
    RefDS(_plural);
    *((int *)(_2+16)) = _plural;
    _3143 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3143;
    _3143 = EPrintf(-9999999, _3140, _3143);
    DeRefDS(_0);
    RefDS(_3143);
    _6CompileErr(_3143);

    // end procedure
    DeRefDSi(_only);
    DeRefDSi(_plural);
    DeRefDSi(_3143);
    DeRef(_3136);
    return 0;
    ;
}


int _15ParseArgs(int _subsym)
{
    int _n;
    int _tok = 0;
    int _3151 = 0;
    int _3147 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_subsym)) {
        _1 = (long)(DBL_PTR(_subsym)->dbl);
        DeRefDS(_subsym);
        _subsym = _1;
    }

    //     n = SymTab[subsym][S_NUM_ARGS]
    _2 = (int)SEQ_PTR(_4SymTab);
    _3147 = (int)*(((s1_ptr)_2)->base + _subsym);
    RefDS(_3147);
    _2 = (int)SEQ_PTR(_3147);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     short_circuit -= 1
    _15short_circuit = _15short_circuit - 1;

    //     for i = 1 to n do
    DeRefDS(_3147);
    _3147 = _n;
    { int _i;
        _i = 1;
L1:
        if (_i > _3147)
            goto L2;

        // 	call_proc(forward_expr, {})
        _0 = (int)_00[_15forward_expr].addr;
        (*(int (*)())_0)(
                             );

        // 	if i != n then 
        if (_i == _n)
            goto L3;

        // 	    tok = next_token()
        _0 = _tok;
        _tok = _15next_token();
        DeRef(_0);

        // 	    if tok[T_ID] != COMMA then
        DeRef(_3151);
        _2 = (int)SEQ_PTR(_tok);
        _3151 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3151);
        if (binary_op_a(EQUALS, _3151, -30))
            goto L4;

        // 		if tok[T_ID] = RIGHT_ROUND then
        DeRef(_3151);
        _2 = (int)SEQ_PTR(_tok);
        _3151 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3151);
        if (binary_op_a(NOTEQ, _3151, -27))
            goto L5;

        // 		    WrongNumberArgs(subsym, "")
        RefDS(_39);
        _15WrongNumberArgs(_subsym, _39);
        goto L6;
L5:

        // 		    putback(tok)
        RefDS(_tok);
        _15putback(_tok);

        // 		    tok_match(COMMA)
        _15tok_match(-30);
L6:
L4:
L3:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     short_circuit += 1
    _15short_circuit = _15short_circuit + 1;

    //     if tok[T_ID] != RIGHT_ROUND then
    DeRef(_3151);
    _2 = (int)SEQ_PTR(_tok);
    _3151 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3151);
    if (binary_op_a(EQUALS, _3151, -27))
        goto L7;

    // 	if tok[T_ID] = COMMA then
    DeRef(_3151);
    _2 = (int)SEQ_PTR(_tok);
    _3151 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3151);
    if (binary_op_a(NOTEQ, _3151, -30))
        goto L8;

    // 	    WrongNumberArgs(subsym, "only ")
    RefDS(_3163);
    _15WrongNumberArgs(_subsym, _3163);
    goto L9;
L8:

    // 	    putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	    tok_match(RIGHT_ROUND)
    _15tok_match(-27);
L9:
L7:

    // end procedure
    DeRef(_tok);
    DeRef(_3151);
    DeRef(_3147);
    return 0;
    ;
}


int _15Factor()
{
    int _tok = 0;
    int _id;
    int _n;
    int _scope;
    int _opcode;
    int _e;
    int _save_factors;
    int _save_lhs_subs_level;
    int _sym;
    int _3169 = 0;
    int _3173 = 0;
    int _3164 = 0;
    int _0, _1, _2, _3;
    

    //     factors += 1
    _15factors = _15factors + 1;

    //     tok = next_token()
    _tok = _15next_token();

    //     id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    //     if id = VARIABLE or id = QUALIFIED_VARIABLE then
    _3164 = (_id == -100);
    if (_3164 != 0) {
        goto L1;
    }
    _3169 = (_id == 515);
L2:
    if (_3169 == 0)
        goto L3;
L1:

    // 	sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	UndefinedVar(sym)
    _15UndefinedVar(_sym);

    // 	SymTab[sym][S_USAGE] = or_bits(SymTab[sym][S_USAGE], U_READ)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    DeRef(_3173);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3173 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3173);
    _0 = _3173;
    _2 = (int)SEQ_PTR(_3173);
    _3173 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_3173);
    DeRefDS(_0);
    _0 = _3173;
    if (IS_ATOM_INT(_3173)) {
        _3173 = (_3173 | 1);
    }
    else {
        _3173 = binary_op(OR_BITS, _3173, 1);
    }
    DeRef(_0);
    Ref(_3173);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _3173;
    DeRef(_1);

    // 	InitCheck(sym, TRUE)
    _15InitCheck(_sym, 1);

    // 	emit_opnd(sym)
    _14emit_opnd(_sym);

    // 	if sym = left_sym then
    if (_sym != _15left_sym)
        goto L4;

    // 	    lhs_subs_level = 0 -- start counting subscripts
    _15lhs_subs_level = 0;
L4:

    // 	short_circuit -= 1
    _15short_circuit = _15short_circuit - 1;

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	current_sequence = append(current_sequence, sym)
    Append(&_14current_sequence, _14current_sequence, _sym);

    // 	while tok[T_ID] = LEFT_SQUARE do
L5:
    DeRef(_3173);
    _2 = (int)SEQ_PTR(_tok);
    _3173 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3173);
    if (binary_op_a(NOTEQ, _3173, -28))
        goto L6;

    // 	    if lhs_subs_level >= 0 then
    if (_15lhs_subs_level < 0)
        goto L7;

    // 		lhs_subs_level += 1
    _15lhs_subs_level = _15lhs_subs_level + 1;
L7:

    // 	    save_factors = factors
    _save_factors = _15factors;

    // 	    save_lhs_subs_level = lhs_subs_level
    _save_lhs_subs_level = _15lhs_subs_level;

    // 	    call_proc(forward_expr, {})
    _0 = (int)_00[_15forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	    if tok[T_ID] = SLICE then
    DeRef(_3173);
    _2 = (int)SEQ_PTR(_tok);
    _3173 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3173);
    if (binary_op_a(NOTEQ, _3173, 516))
        goto L8;

    // 		call_proc(forward_expr, {})
    _0 = (int)_00[_15forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 		emit_op(RHS_SLICE)
    _14emit_op(46);

    // 		tok_match(RIGHT_SQUARE)
    _15tok_match(-29);

    // 		tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    // 		exit
    goto L6;
    goto L9;
L8:

    // 		putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 		tok_match(RIGHT_SQUARE)
    _15tok_match(-29);

    // 		current_sequence = current_sequence[1..$-1]
    DeRef(_3173);
    _3173 = SEQ_PTR(_14current_sequence)->length;
    _3173 = _3173 - 1;
    rhs_slice_target = (object_ptr)&_14current_sequence;
    RHS_Slice((s1_ptr)_14current_sequence, 1, _3173);

    // 		emit_op(RHS_SUBS) -- current_sequence will be updated
    _14emit_op(25);
L9:

    // 	    factors = save_factors
    _15factors = _save_factors;

    // 	    lhs_subs_level = save_lhs_subs_level
    _15lhs_subs_level = _save_lhs_subs_level;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	end while
    goto L5;
L6:

    // 	current_sequence = current_sequence[1..$-1]
    DeRef(_3173);
    _3173 = SEQ_PTR(_14current_sequence)->length;
    _3173 = _3173 - 1;
    rhs_slice_target = (object_ptr)&_14current_sequence;
    RHS_Slice((s1_ptr)_14current_sequence, 1, _3173);

    // 	putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	short_circuit += 1
    _15short_circuit = _15short_circuit + 1;
    goto LA;
L3:

    //     elsif id = DOLLAR then
    if (_id != -22)
        goto LB;

    // 	if length(current_sequence) then
    DeRef(_3173);
    _3173 = SEQ_PTR(_14current_sequence)->length;
    if (_3173 == 0)
        goto LC;

    // 	    emit_op(DOLLAR)
    _14emit_op(-22);
    goto LA;
LC:

    // 	    CompileErr("'$' must only appear between '[' and ']'")
    RefDS(_3198);
    _6CompileErr(_3198);
LD:
    goto LA;
LB:

    //     elsif id = ATOM then
    if (_id != 502)
        goto LE;

    // 	emit_opnd(tok[T_SYM])
    DeRef(_3173);
    _2 = (int)SEQ_PTR(_tok);
    _3173 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3173);
    Ref(_3173);
    _14emit_opnd(_3173);
    goto LA;
LE:

    //     elsif id = LEFT_BRACE then
    if (_id != -24)
        goto LF;

    // 	n = Expr_list()
    _n = _15Expr_list();

    // 	tok_match(RIGHT_BRACE)
    _15tok_match(-25);

    // 	op_info1 = n
    _14op_info1 = _n;

    // 	emit_op(RIGHT_BRACE_N)
    _14emit_op(31);
    goto LA;
LF:

    //     elsif id = STRING then
    if (_id != 503)
        goto L10;

    // 	emit_opnd(tok[T_SYM])
    DeRef(_3173);
    _2 = (int)SEQ_PTR(_tok);
    _3173 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3173);
    Ref(_3173);
    _14emit_opnd(_3173);
    goto LA;
L10:

    //     elsif id = LEFT_ROUND then
    if (_id != -26)
        goto L11;

    // 	call_proc(forward_expr, {})
    _0 = (int)_00[_15forward_expr].addr;
    (*(int (*)())_0)(
                         );

    // 	tok_match(RIGHT_ROUND)
    _15tok_match(-27);
    goto LA;
L11:

    //     elsif find(id, {FUNC, TYPE, QUALIFIED_FUNC, QUALIFIED_TYPE}) then
    _0 = _3173;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 501;
    *((int *)(_2+8)) = 504;
    *((int *)(_2+12)) = 524;
    *((int *)(_2+16)) = 526;
    _3173 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3173;
    _3173 = find(_id, _3173);
    DeRefDSi(_0);
    if (_3173 == 0)
        goto L12;

    // 	e = SymTab[tok[T_SYM]][S_EFFECT]
    _2 = (int)SEQ_PTR(_tok);
    _3173 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3173);
    _0 = _3173;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3173))
        _3173 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3173)->dbl));
    else
        _3173 = (int)*(((s1_ptr)_2)->base + _3173);
    RefDS(_3173);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_3173);
    _e = (int)*(((s1_ptr)_2)->base + 21);
    if (!IS_ATOM_INT(_e))
        _e = (long)DBL_PTR(_e)->dbl;

    // 	if e then
    if (_e == 0)
        goto L13;

    // 	    if e = E_ALL_EFFECT or tok[T_SYM] > left_sym then
    DeRefDS(_3173);
    _3173 = (_e == 1073741823);
    if (_3173 != 0) {
        goto L14;
    }
    DeRef(_3164);
    _2 = (int)SEQ_PTR(_tok);
    _3164 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3164);
    _0 = _3164;
    if (IS_ATOM_INT(_3164)) {
        _3164 = (_3164 > _15left_sym);
    }
    else {
        _3164 = binary_op(GREATER, _3164, _15left_sym);
    }
    DeRef(_0);
L15:
    if (_3164 == 0) {
        goto L16;
    }
    else {
        if (!IS_ATOM_INT(_3164) && DBL_PTR(_3164)->dbl == 0.0)
            goto L16;
    }
L14:

    // 		side_effect_calls = or_bits(side_effect_calls, e)
    _15side_effect_calls = (_15side_effect_calls | _e);
L16:

    // 	    SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    DeRef(_3169);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3169 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_3169);
    _0 = _3169;
    _2 = (int)SEQ_PTR(_3169);
    _3169 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3169);
    DeRefDS(_0);
    _0 = _3169;
    if (IS_ATOM_INT(_3169)) {
        _3169 = (_3169 | _e);
    }
    else {
        _3169 = binary_op(OR_BITS, _3169, _e);
    }
    DeRef(_0);
    Ref(_3169);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _3169;
    DeRef(_1);

    // 	    if short_circuit > 0 and short_circuit_B and
    DeRef(_3169);
    _3169 = (_15short_circuit > 0);
    if (_3169 == 0) {
        _3169 = 0;
        goto L17;
    }
    _3169 = (_15short_circuit_B != 0);
L17:
    if (_3169 == 0) {
        goto L18;
    }
    DeRef(_3173);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 501;
    ((int *)_2)[2] = 524;
    _3173 = MAKE_SEQ(_1);
    _0 = _3173;
    _3173 = find(_id, _3173);
    DeRefDSi(_0);
L19:
    if (_3173 == 0)
        goto L18;

    // 		Warning(sprintf(
    DeRef(_3173);
    _2 = (int)SEQ_PTR(_4file_name);
    _3173 = (int)*(((s1_ptr)_2)->base + _4current_file_no);
    RefDS(_3173);
    DeRef(_3169);
    _2 = (int)SEQ_PTR(_tok);
    _3169 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3169);
    _0 = _3169;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3169))
        _3169 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3169)->dbl));
    else
        _3169 = (int)*(((s1_ptr)_2)->base + _3169);
    RefDS(_3169);
    DeRef(_0);
    _0 = _3169;
    _2 = (int)SEQ_PTR(_3169);
    _3169 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3169);
    DeRefDS(_0);
    _0 = _3169;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_3173);
    *((int *)(_2+4)) = _3173;
    *((int *)(_2+8)) = _4line_number;
    Ref(_3169);
    *((int *)(_2+12)) = _3169;
    _3169 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3169;
    _3169 = EPrintf(-9999999, _3226, _3169);
    DeRefDS(_0);
    RefDS(_3169);
    _6Warning(_3169);
L18:
L13:

    // 	tok_match(LEFT_ROUND)
    _15tok_match(-26);

    // 	scope = SymTab[tok[T_SYM]][S_SCOPE]
    DeRef(_3169);
    _2 = (int)SEQ_PTR(_tok);
    _3169 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3169);
    _0 = _3169;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3169))
        _3169 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3169)->dbl));
    else
        _3169 = (int)*(((s1_ptr)_2)->base + _3169);
    RefDS(_3169);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_3169);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    // 	opcode = SymTab[tok[T_SYM]][S_OPCODE]
    DeRefDS(_3169);
    _2 = (int)SEQ_PTR(_tok);
    _3169 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3169);
    _0 = _3169;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3169))
        _3169 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3169)->dbl));
    else
        _3169 = (int)*(((s1_ptr)_2)->base + _3169);
    RefDS(_3169);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_3169);
    _opcode = (int)*(((s1_ptr)_2)->base + 19);
    if (!IS_ATOM_INT(_opcode))
        _opcode = (long)DBL_PTR(_opcode)->dbl;

    // 	ParseArgs(tok[T_SYM])
    DeRefDS(_3169);
    _2 = (int)SEQ_PTR(_tok);
    _3169 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3169);
    Ref(_3169);
    _15ParseArgs(_3169);

    // 	if scope = SC_PREDEF then
    if (_scope != 7)
        goto L1A;

    // 	    emit_op(opcode)
    _14emit_op(_opcode);
    goto LA;
L1A:

    // 	    op_info1 = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _14op_info1 = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_14op_info1))
        _14op_info1 = (long)DBL_PTR(_14op_info1)->dbl;

    // 	    emit_op(PROC)
    _14emit_op(27);

    // 	    if not TRANSLATE then 
L1B:
    goto LA;
L12:

    // 	CompileErr(sprintf(
    _0 = _3169;
    _3169 = _14LexName(_id);
    DeRef(_0);
    _0 = _3169;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3169);
    *((int *)(_2+4)) = _3169;
    _3169 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3169;
    _3169 = EPrintf(-9999999, _3243, _3169);
    DeRefDS(_0);
    RefDS(_3169);
    _6CompileErr(_3169);
LA:

    // end procedure
    DeRef(_tok);
    DeRef(_3169);
    DeRef(_3173);
    DeRef(_3164);
    return 0;
    ;
}


int _15UFactor()
{
    int _tok = 0;
    int _3247 = 0;
    int _0, _1, _2;
    

    //     tok = next_token()
    _tok = _15next_token();

    //     if tok[T_ID] = MINUS then
    _2 = (int)SEQ_PTR(_tok);
    _3247 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3247);
    if (binary_op_a(NOTEQ, _3247, 10))
        goto L1;

    // 	Factor()
    _15Factor();

    // 	emit_op(UMINUS)
    _14emit_op(12);
    goto L2;
L1:

    //     elsif tok[T_ID] = NOT then
    DeRef(_3247);
    _2 = (int)SEQ_PTR(_tok);
    _3247 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3247);
    if (binary_op_a(NOTEQ, _3247, 7))
        goto L3;

    // 	Factor()
    _15Factor();

    // 	emit_op(NOT)
    _14emit_op(7);
    goto L2;
L3:

    //     elsif tok[T_ID] = PLUS then
    DeRef(_3247);
    _2 = (int)SEQ_PTR(_tok);
    _3247 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3247);
    if (binary_op_a(NOTEQ, _3247, 11))
        goto L4;

    // 	Factor()
    _15Factor();
    goto L2;
L4:

    // 	putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	Factor()
    _15Factor();
L2:

    // end procedure
    DeRef(_tok);
    DeRef(_3247);
    return 0;
    ;
}


int _15term()
{
    int _tok = 0;
    int _3258 = 0;
    int _3254 = 0;
    int _0, _1, _2;
    

    //     UFactor()   
    _15UFactor();

    //     tok = next_token() 
    _tok = _15next_token();

    //     while tok[T_ID] = MULTIPLY or tok[T_ID] = DIVIDE do
L1:
    DeRef(_3254);
    _2 = (int)SEQ_PTR(_tok);
    _3254 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3254);
    _0 = _3254;
    if (IS_ATOM_INT(_3254)) {
        _3254 = (_3254 == 13);
    }
    else {
        _3254 = binary_op(EQUALS, _3254, 13);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3254)) {
        if (_3254 != 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_3254)->dbl != 0.0) {
            goto L2;
        }
    }
    DeRef(_3258);
    _2 = (int)SEQ_PTR(_tok);
    _3258 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3258);
    _0 = _3258;
    if (IS_ATOM_INT(_3258)) {
        _3258 = (_3258 == 14);
    }
    else {
        _3258 = binary_op(EQUALS, _3258, 14);
    }
    DeRef(_0);
L3:
    if (_3258 <= 0) {
        if (_3258 == 0) {
            goto L4;
        }
        else {
            if (!IS_ATOM_INT(_3258) && DBL_PTR(_3258)->dbl == 0.0)
                goto L4;
        }
    }
L2:

    // 	UFactor() 
    _15UFactor();

    // 	emit_op(tok[T_ID]) 
    DeRef(_3258);
    _2 = (int)SEQ_PTR(_tok);
    _3258 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3258);
    Ref(_3258);
    _14emit_op(_3258);

    // 	tok = next_token() 
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    //     end while
    goto L1;
L4:

    //     return tok
    DeRef(_3258);
    DeRef(_3254);
    return _tok;
    ;
}


int _15aexpr()
{
    int _tok = 0;
    int _id;
    int _3266 = 0;
    int _3262 = 0;
    int _0, _1, _2;
    

    //     tok = term()
    _tok = _15term();

    //     while tok[T_ID] = PLUS or tok[T_ID] = MINUS do
L1:
    DeRef(_3262);
    _2 = (int)SEQ_PTR(_tok);
    _3262 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3262);
    _0 = _3262;
    if (IS_ATOM_INT(_3262)) {
        _3262 = (_3262 == 11);
    }
    else {
        _3262 = binary_op(EQUALS, _3262, 11);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3262)) {
        if (_3262 != 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_3262)->dbl != 0.0) {
            goto L2;
        }
    }
    DeRef(_3266);
    _2 = (int)SEQ_PTR(_tok);
    _3266 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3266);
    _0 = _3266;
    if (IS_ATOM_INT(_3266)) {
        _3266 = (_3266 == 10);
    }
    else {
        _3266 = binary_op(EQUALS, _3266, 10);
    }
    DeRef(_0);
L3:
    if (_3266 <= 0) {
        if (_3266 == 0) {
            goto L4;
        }
        else {
            if (!IS_ATOM_INT(_3266) && DBL_PTR(_3266)->dbl == 0.0)
                goto L4;
        }
    }
L2:

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	tok = term()
    _0 = _tok;
    _tok = _15term();
    DeRefDS(_0);

    // 	emit_op(id) 
    _14emit_op(_id);

    //     end while
    goto L1;
L4:

    //     return tok
    DeRef(_3266);
    DeRef(_3262);
    return _tok;
    ;
}


int _15cexpr()
{
    int _tok = 0;
    int _concat_count;
    int _3270 = 0;
    int _0, _1, _2;
    

    //     tok = aexpr()
    _tok = _15aexpr();

    //     concat_count = 0 
    _concat_count = 0;

    //     while tok[T_ID] = CONCAT do
L1:
    DeRef(_3270);
    _2 = (int)SEQ_PTR(_tok);
    _3270 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3270);
    if (binary_op_a(NOTEQ, _3270, 15))
        goto L2;

    // 	tok = aexpr()
    _0 = _tok;
    _tok = _15aexpr();
    DeRefDS(_0);

    // 	concat_count += 1 
    _concat_count = _concat_count + 1;

    //     end while
    goto L1;
L2:

    //     if concat_count = 1 then
    if (_concat_count != 1)
        goto L3;

    // 	emit_op(CONCAT)
    _14emit_op(15);
    goto L4;
L3:

    //     elsif concat_count > 1 then
    if (_concat_count <= 1)
        goto L5;

    // 	op_info1 = concat_count+1 
    _14op_info1 = _concat_count + 1;

    // 	emit_op(CONCAT_N) 
    _14emit_op(159);
L5:
L4:

    //     return tok
    DeRef(_3270);
    return _tok;
    ;
}


int _15rexpr()
{
    int _tok = 0;
    int _id;
    int _3282 = 0;
    int _3278 = 0;
    int _0, _1, _2;
    

    //     tok = cexpr()
    _tok = _15cexpr();

    //     while tok[T_ID] <= GREATER and tok[T_ID] >= LESS do
L1:
    DeRef(_3278);
    _2 = (int)SEQ_PTR(_tok);
    _3278 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3278);
    _0 = _3278;
    if (IS_ATOM_INT(_3278)) {
        _3278 = (_3278 <= 6);
    }
    else {
        _3278 = binary_op(LESSEQ, _3278, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3278)) {
        if (_3278 == 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_3278)->dbl == 0.0) {
            goto L2;
        }
    }
    DeRef(_3282);
    _2 = (int)SEQ_PTR(_tok);
    _3282 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3282);
    _0 = _3282;
    if (IS_ATOM_INT(_3282)) {
        _3282 = (_3282 >= 1);
    }
    else {
        _3282 = binary_op(GREATEREQ, _3282, 1);
    }
    DeRef(_0);
L3:
    if (_3282 <= 0) {
        if (_3282 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_3282) && DBL_PTR(_3282)->dbl == 0.0)
                goto L2;
        }
    }

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	tok = cexpr()
    _0 = _tok;
    _tok = _15cexpr();
    DeRefDS(_0);

    // 	emit_op(id)
    _14emit_op(_id);

    //     end while
    goto L1;
L2:

    //     return tok
    DeRef(_3282);
    DeRef(_3278);
    return _tok;
    ;
}


int _15Expr()
{
    int _tok = 0;
    int _id;
    int _patch;
    int _3286 = 0;
    int _3288 = 0;
    int _0, _1, _2;
    

    //     id = -1
    _id = -1;

    //     patch = 0
    _patch = 0;

    //     while TRUE do 
L1:

    // 	if id != -1 and id != XOR and short_circuit > 0 then
    DeRef(_3286);
    _3286 = (_id != -1);
    if (_3286 == 0) {
        _3286 = 0;
        goto L2;
    }
    DeRef(_3288);
    _3288 = (_id != 154);
    _3286 = (_3288 != 0);
L2:
    if (_3286 == 0) {
        goto L3;
    }
    DeRef(_3286);
    _3286 = (_15short_circuit > 0);
L4:
    if (_3286 == 0)
        goto L3;

    // 	    if id = OR then
    if (_id != 9)
        goto L5;

    // 		emit_op(SC1_OR)
    _14emit_op(145);
    goto L6;
L5:

    // 		emit_op(SC1_AND)
    _14emit_op(143);
L6:

    // 	    patch = length(Code)+1
    DeRef(_3286);
    _3286 = SEQ_PTR(_4Code)->length;
    _patch = _3286 + 1;

    // 	    emit_forward_addr()
    _15emit_forward_addr();

    // 	    short_circuit_B = TRUE
    _15short_circuit_B = 1;
L3:

    // 	tok = rexpr()
    _0 = _tok;
    _tok = _15rexpr();
    DeRef(_0);

    // 	if id != -1 then
    if (_id == -1)
        goto L7;

    // 	    if id != XOR and short_circuit > 0 then
    DeRef(_3286);
    _3286 = (_id != 154);
    if (_3286 == 0) {
        goto L8;
    }
    DeRef(_3288);
    _3288 = (_15short_circuit > 0);
L9:
    if (_3288 == 0)
        goto L8;

    // 		if tok[T_ID] != THEN and tok[T_ID] != DO then
    DeRef(_3288);
    _2 = (int)SEQ_PTR(_tok);
    _3288 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3288);
    _0 = _3288;
    if (IS_ATOM_INT(_3288)) {
        _3288 = (_3288 != 409);
    }
    else {
        _3288 = binary_op(NOTEQ, _3288, 409);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3288)) {
        if (_3288 == 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_3288)->dbl == 0.0) {
            goto LA;
        }
    }
    DeRef(_3286);
    _2 = (int)SEQ_PTR(_tok);
    _3286 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3286);
    _0 = _3286;
    if (IS_ATOM_INT(_3286)) {
        _3286 = (_3286 != 410);
    }
    else {
        _3286 = binary_op(NOTEQ, _3286, 410);
    }
    DeRef(_0);
LB:
    if (_3286 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_3286) && DBL_PTR(_3286)->dbl == 0.0)
            goto LA;
    }

    // 		    if id = OR then
    if (_id != 9)
        goto LC;

    // 			emit_op(SC2_OR)
    _14emit_op(146);
    goto LD;
LC:

    // 			emit_op(SC2_AND)
    _14emit_op(144);
LE:
    goto LD;
LA:

    // 		    SC1_type = id -- if/while/elsif must patch
    _15SC1_type = _id;

    // 		    emit_op(SC2_NULL)
    _14emit_op(147);
LD:

    // 		if TRANSLATE then

    // 		    emit_op(NOP1)   -- to get label here
    _14emit_op(161);
LF:

    // 		backpatch(patch, length(Code)+1)
    DeRef(_3286);
    _3286 = SEQ_PTR(_4Code)->length;
    _3286 = _3286 + 1;
    _14backpatch(_patch, _3286);
    goto L10;
L8:

    // 		emit_op(id)
    _14emit_op(_id);
L10:
L7:

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	if id != OR and id != AND and id != XOR then
    DeRef(_3286);
    _3286 = (_id != 9);
    if (_3286 == 0) {
        _3286 = 0;
        goto L11;
    }
    DeRef(_3288);
    _3288 = (_id != 8);
    _3286 = (_3288 != 0);
L11:
    if (_3286 == 0) {
        goto L1;
    }
    DeRef(_3286);
    _3286 = (_id != 154);
L12:
    if (_3286 == 0)
        goto L1;

    // 	    exit
    goto L13;
L14:

    //     end while
    goto L1;
L13:

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    //     SC1_patch = patch -- extra line
    _15SC1_patch = _patch;

    // end procedure
    DeRefDS(_tok);
    DeRef(_3286);
    DeRef(_3288);
    return 0;
    ;
}


int _15TypeCheck(int _var)
{
    int _which_type;
    int _3330 = 0;
    int _3315 = 0;
    int _0, _1, _2;
    

    //     which_type = SymTab[var][S_VTYPE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _3315 = (int)*(((s1_ptr)_2)->base + _var);
    RefDS(_3315);
    _2 = (int)SEQ_PTR(_3315);
    _which_type = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_which_type))
        _which_type = (long)DBL_PTR(_which_type)->dbl;

    //     if TRANSLATE then

    // 	if OpTypeCheck then
    if (_4OpTypeCheck == 0)
        goto L1;

    // 	    if which_type != object_type then
    if (_which_type == _10object_type)
        goto L1;

    // 		if SymTab[which_type][S_EFFECT] then
    DeRefDS(_3315);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3315 = (int)*(((s1_ptr)_2)->base + _which_type);
    RefDS(_3315);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_3315);
    _3315 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3315);
    DeRefDS(_0);
    if (_3315 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_3315) && DBL_PTR(_3315)->dbl == 0.0)
            goto L1;
    }

    // 		    emit_opnd(var)
    _14emit_opnd(_var);

    // 		    op_info1 = which_type
    _14op_info1 = _which_type;

    // 		    emit_op(PROC)
    _14emit_op(27);

    // 		    emit_op(TYPE_CHECK)
    _14emit_op(65);
L2:
L3:
L4:
    goto L1;
L5:

    // 	if OpTypeCheck then
    if (_4OpTypeCheck == 0)
        goto L6;

    // 	    if which_type != object_type then
    if (_which_type == _10object_type)
        goto L7;

    // 		if which_type = integer_type then
    if (_which_type != _10integer_type)
        goto L8;

    // 		    op_info1 = var
    _14op_info1 = _var;

    // 		    emit_op(INTEGER_CHECK)
    _14emit_op(96);
    goto L9;
L8:

    // 		elsif which_type = sequence_type then
    if (_which_type != _10sequence_type)
        goto LA;

    // 		    op_info1 = var
    _14op_info1 = _var;

    // 		    emit_op(SEQUENCE_CHECK)
    _14emit_op(97);
    goto L9;
LA:

    // 		elsif which_type = atom_type then
    if (_which_type != _10atom_type)
        goto LB;

    // 		    op_info1 = var
    _14op_info1 = _var;

    // 		    emit_op(ATOM_CHECK)
    _14emit_op(101);
    goto L9;
LB:

    // 		    if SymTab[SymTab[which_type][S_NEXT]][S_VTYPE] = 
    DeRef(_3315);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3315 = (int)*(((s1_ptr)_2)->base + _which_type);
    RefDS(_3315);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_3315);
    _3315 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3315);
    DeRefDS(_0);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3315))
        _3315 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3315)->dbl));
    else
        _3315 = (int)*(((s1_ptr)_2)->base + _3315);
    RefDS(_3315);
    DeRef(_0);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_3315);
    _3315 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_3315);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3315, _10integer_type))
        goto LC;

    // 			op_info1 = var
    _14op_info1 = _var;

    // 			emit_op(INTEGER_CHECK) -- need integer conversion 
    _14emit_op(96);
LC:

    // 		    emit_opnd(var)
    _14emit_opnd(_var);

    // 		    op_info1 = which_type
    _14op_info1 = _which_type;

    // 		    emit_op(PROC)
    _14emit_op(27);

    // 		    emit_op(TYPE_CHECK)
    _14emit_op(65);
L9:
L7:
L6:
L1:

    //     if TRANSLATE or not OpTypeCheck then
    if (1 != 0) {
        goto LD;
    }
    DeRef(_3330);
    _3330 = (_4OpTypeCheck == 0);
LE:
    if (_3330 == 0)
        goto LF;
LD:

    // 	op_info1 = var
    _14op_info1 = _var;

    // 	if which_type = sequence_type or
    DeRef(_3330);
    _3330 = (_which_type == _10sequence_type);
    if (_3330 != 0) {
        goto L10;
    }
    DeRef(_3315);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3315 = (int)*(((s1_ptr)_2)->base + _which_type);
    RefDS(_3315);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_3315);
    _3315 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3315);
    DeRefDS(_0);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3315))
        _3315 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3315)->dbl));
    else
        _3315 = (int)*(((s1_ptr)_2)->base + _3315);
    RefDS(_3315);
    DeRef(_0);
    _0 = _3315;
    _2 = (int)SEQ_PTR(_3315);
    _3315 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_3315);
    DeRefDS(_0);
    _0 = _3315;
    if (IS_ATOM_INT(_3315)) {
        _3315 = (_3315 == _10sequence_type);
    }
    else {
        _3315 = binary_op(EQUALS, _3315, _10sequence_type);
    }
    DeRef(_0);
L11:
    if (_3315 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_3315) && DBL_PTR(_3315)->dbl == 0.0)
            goto L12;
    }
L10:

    // 	    emit_op(SEQUENCE_CHECK)
    _14emit_op(97);
    goto L13;
L12:

    // 	elsif which_type = integer_type or
    DeRef(_3315);
    _3315 = (_which_type == _10integer_type);
    if (_3315 != 0) {
        goto L14;
    }
    DeRef(_3330);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3330 = (int)*(((s1_ptr)_2)->base + _which_type);
    RefDS(_3330);
    _0 = _3330;
    _2 = (int)SEQ_PTR(_3330);
    _3330 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3330);
    DeRefDS(_0);
    _0 = _3330;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3330))
        _3330 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3330)->dbl));
    else
        _3330 = (int)*(((s1_ptr)_2)->base + _3330);
    RefDS(_3330);
    DeRef(_0);
    _0 = _3330;
    _2 = (int)SEQ_PTR(_3330);
    _3330 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_3330);
    DeRefDS(_0);
    _0 = _3330;
    if (IS_ATOM_INT(_3330)) {
        _3330 = (_3330 == _10integer_type);
    }
    else {
        _3330 = binary_op(EQUALS, _3330, _10integer_type);
    }
    DeRef(_0);
L15:
    if (_3330 == 0) {
        goto L16;
    }
    else {
        if (!IS_ATOM_INT(_3330) && DBL_PTR(_3330)->dbl == 0.0)
            goto L16;
    }
L14:

    // 	    emit_op(INTEGER_CHECK)
    _14emit_op(96);
L16:
L13:
LF:

    // end procedure
    DeRef(_3330);
    DeRef(_3315);
    return 0;
    ;
}


