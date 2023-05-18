// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _15InitGlobals()
{
    int _0, _1, _2;
    

    //     ResetTP()
    _11ResetTP();

    //     OpTypeCheck = TRUE
    _4OpTypeCheck = 1;

    //     OpWarning = TRUE
    _4OpWarning = 1;

    // end procedure
    return 0;
    ;
}


int _15not_supported_compile(int _feature)
{
    int _3840 = 0;
    int _0, _1, _2;
    

    //     CompileErr(sprintf("%s is not supported in Euphoria for %s", 
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _feature;
    RefDS(_feature);
    ((int *)_2)[2] = _4version_name;
    RefDS(_4version_name);
    _3840 = MAKE_SEQ(_1);
    _0 = _3840;
    _3840 = EPrintf(-9999999, _648, _3840);
    DeRefDS(_0);
    RefDS(_3840);
    _6CompileErr(_3840);

    // end procedure
    DeRefDSi(_feature);
    DeRefDSi(_3840);
    return 0;
    ;
}


int _15SetWith(int _on_off)
{
    int _option = 0;
    int _tok = 0;
    int _3843 = 0;
    int _3849;
    int _0, _1, _2;
    

    //     option = StringToken()
    _option = _11StringToken();

    //     if equal(option, "type_check") then
    if (_option == _3844)
        _3843 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_3844))
        _3843 = 0;
    else
        _3843 = (compare(_option, _3844) == 0);
    if (_3843 == 0)
        goto L1;

    // 	OpTypeCheck = on_off
    _4OpTypeCheck = _on_off;
    goto L2;
L1:

    //     elsif equal(option, "profile") then
    DeRef(_3843);
    if (_option == _828)
        _3843 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_828))
        _3843 = 0;
    else
        _3843 = (compare(_option, _828) == 0);
    if (_3843 == 0)
        goto L3;

    // 	if not TRANSLATE and not BIND then
    _3843 = (0 == 0);
    if (_3843 == 0) {
        goto L2;
    }
    _3849 = (0 == 0);
L4:
    if (_3849 == 0)
        goto L2;

    // 	    OpProfileStatement = on_off
    _4OpProfileStatement = _on_off;

    // 	    if OpProfileStatement then
    if (_4OpProfileStatement == 0)
        goto L2;

    // 		if AnyTimeProfile then
    if (_11AnyTimeProfile == 0)
        goto L5;

    // 		    Warning(mix_msg)
    RefDS(_15mix_msg);
    _6Warning(_15mix_msg);

    // 		    OpProfileStatement = FALSE
    _4OpProfileStatement = 0;
    goto L2;
L5:

    // 		    AnyStatementProfile = TRUE
    _11AnyStatementProfile = 1;
L6:
L7:
L8:
    goto L2;
L3:

    //     elsif equal(option, "profile_time") then
    if (_option == _3850)
        _3849 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_3850))
        _3849 = 0;
    else
        _3849 = (compare(_option, _3850) == 0);
    if (_3849 == 0)
        goto L9;

    // 	if not TRANSLATE and not BIND then
    _3849 = (0 == 0);
    if (_3849 == 0) {
        goto L2;
    }
    DeRef(_3843);
    _3843 = (0 == 0);
LA:
    if (_3843 == 0)
        goto L2;

    // 	    if not EDOS then
    if (_4EDOS != 0)
        goto LB;

    // 		if on_off then
    if (_on_off == 0)
        goto LC;

    // 		    not_supported_compile("profile_time")
    RefDS(_3850);
    _15not_supported_compile(_3850);
LC:
LB:

    // 	    OpProfileTime = on_off
    _4OpProfileTime = _on_off;

    // 	    if OpProfileTime then
    if (_4OpProfileTime == 0)
        goto L2;

    // 		if AnyStatementProfile then
    if (_11AnyStatementProfile == 0)
        goto LD;

    // 		    Warning(mix_msg)
    RefDS(_15mix_msg);
    _6Warning(_15mix_msg);

    // 		    OpProfileTime = FALSE
    _4OpProfileTime = 0;
LD:

    // 		tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 		if tok[T_ID] = ATOM then
    DeRef(_3843);
    _2 = (int)SEQ_PTR(_tok);
    _3843 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3843);
    if (binary_op_a(NOTEQ, _3843, 502))
        goto LE;

    // 		    if integer(SymTab[tok[T_SYM]][S_OBJ]) then
    DeRef(_3843);
    _2 = (int)SEQ_PTR(_tok);
    _3843 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3843);
    _0 = _3843;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3843))
        _3843 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3843)->dbl));
    else
        _3843 = (int)*(((s1_ptr)_2)->base + _3843);
    RefDS(_3843);
    DeRef(_0);
    _0 = _3843;
    _2 = (int)SEQ_PTR(_3843);
    _3843 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3843);
    DeRefDS(_0);
    _0 = _3843;
    if (IS_ATOM_INT(_3843))
        _3843 = 1;
    else if (IS_ATOM_DBL(_3843))
        _3843 = IS_ATOM_INT(DoubleToInt(_3843));
    else
        _3843 = 0;
    DeRef(_0);
    if (_3843 == 0)
        goto LF;

    // 			sample_size = SymTab[tok[T_SYM]][S_OBJ]
    _2 = (int)SEQ_PTR(_tok);
    _3843 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3843);
    _0 = _3843;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_3843))
        _3843 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3843)->dbl));
    else
        _3843 = (int)*(((s1_ptr)_2)->base + _3843);
    RefDS(_3843);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_3843);
    _15sample_size = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_15sample_size))
        _15sample_size = (long)DBL_PTR(_15sample_size)->dbl;
    goto L10;
LF:

    // 			sample_size = -1
    _15sample_size = -1;
L10:

    // 		    if sample_size < 1 and OpProfileTime then
    DeRef(_3843);
    _3843 = (_15sample_size < 1);
    if (_3843 == 0) {
        goto L11;
    }
L12:
    if (_4OpProfileTime == 0)
        goto L11;

    // 			CompileErr("sample size must be a positive integer")
    RefDS(_3868);
    _6CompileErr(_3868);
L13:
    goto L11;
LE:

    // 		    putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 		    sample_size = DEFAULT_SAMPLE_SIZE
    _15sample_size = 25000;
L11:

    // 		if OpProfileTime then
    if (_4OpProfileTime == 0)
        goto L2;

    // 		    if EDOS then
    if (_4EDOS == 0)
        goto L2;

    // 			AnyTimeProfile = TRUE
    _11AnyTimeProfile = 1;
L14:
L15:
L16:
L17:
    goto L2;
L9:

    //     elsif equal(option, "trace") then
    DeRef(_3843);
    if (_option == _758)
        _3843 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_758))
        _3843 = 0;
    else
        _3843 = (compare(_option, _758) == 0);
    if (_3843 == 0)
        goto L18;

    // 	if not BIND then 

    // 	    OpTrace = on_off
    _4OpTrace = _on_off;
L19:
    goto L2;
L18:

    //     elsif equal(option, "warning") then
    DeRef(_3843);
    if (_option == _3871)
        _3843 = 1;
    else if (IS_ATOM_INT(_option) && IS_ATOM_INT(_3871))
        _3843 = 0;
    else
        _3843 = (compare(_option, _3871) == 0);
    if (_3843 == 0)
        goto L1A;

    // 	OpWarning = on_off
    _4OpWarning = _on_off;
    goto L2;
L1A:

    //     elsif on_off and option[1] >= '0' and option[1] <= '9' then
    if (_on_off == 0) {
        DeRef(_3843);
        _3843 = 0;
        goto L1B;
    }
    _2 = (int)SEQ_PTR(_option);
    _3849 = (int)*(((s1_ptr)_2)->base + 1);
    _3849 = (_3849 >= 48);
    _3843 = (_3849 != 0);
L1B:
    if (_3843 == 0) {
        goto L1C;
    }
    DeRef(_3843);
    _2 = (int)SEQ_PTR(_option);
    _3843 = (int)*(((s1_ptr)_2)->base + 1);
    _3843 = (_3843 <= 57);
L1D:
    if (_3843 == 0)
        goto L1C;
    goto L2;
L1C:

    // 	CompileErr("unknown with/without option")
    RefDS(_3879);
    _6CompileErr(_3879);
L2:

    // end procedure
    DeRefi(_option);
    DeRef(_tok);
    DeRef(_3843);
    return 0;
    ;
}


int _15ExecCommand()
{
    int _0, _1, _2;
    

    //     if TRANSLATE then

    //     StraightenBranches()  -- straighten top-level
    _15StraightenBranches();

    // end procedure
    return 0;
    ;
}


int _15parser()
{
    int _tok = 0;
    int _id;
    int _3886 = 0;
    int _3880 = 0;
    int _0, _1, _2, _3;
    

    //     tok = next_token()
    _tok = _15next_token();

    //     while TRUE do  -- infinite loop until scanner aborts
L1:

    // 	start_index = length(Code)+1
    DeRef(_3880);
    _3880 = SEQ_PTR(_4Code)->length;
    _15start_index = _3880 + 1;

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	if id = VARIABLE or id = QUALIFIED_VARIABLE then
    _3880 = (_id == -100);
    if (_3880 != 0) {
        goto L2;
    }
    DeRef(_3886);
    _3886 = (_id == 515);
L3:
    if (_3886 == 0)
        goto L4;
L2:

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Assignment(tok)
    RefDS(_tok);
    _15Assignment(_tok);

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L4:

    // 	elsif id = PROCEDURE or id = FUNCTION or id = TYPE_DECL then
    DeRef(_3886);
    _3886 = (_id == 405);
    if (_3886 != 0) {
        _3886 = 1;
        goto L6;
    }
    DeRef(_3880);
    _3880 = (_id == 406);
    _3886 = (_3880 != 0);
L6:
    if (_3886 != 0) {
        goto L7;
    }
    DeRef(_3886);
    _3886 = (_id == 415);
L8:
    if (_3886 == 0)
        goto L9;
L7:

    // 	    SubProg(tok[T_ID], 0)
    DeRef(_3886);
    _2 = (int)SEQ_PTR(_tok);
    _3886 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3886);
    Ref(_3886);
    _15SubProg(_3886, 0);
    goto L5;
L9:

    // 	elsif id = GLOBAL then
    if (_id != 411)
        goto LA;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	    id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	    if id = TYPE then
    if (_id != 504)
        goto LB;

    // 		Global_declaration(tok[T_SYM], 1)
    DeRef(_3886);
    _2 = (int)SEQ_PTR(_tok);
    _3886 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3886);
    Ref(_3886);
    _15Global_declaration(_3886, 1);
    goto L5;
LB:

    // 	    elsif id = CONSTANT then
    if (_id != 416)
        goto LC;

    // 		Global_declaration(0, 1)
    _15Global_declaration(0, 1);

    // 		ExecCommand()
    _15ExecCommand();
    goto L5;
LC:

    // 	    elsif id = PROCEDURE or id = FUNCTION or id = TYPE_DECL then
    DeRef(_3886);
    _3886 = (_id == 405);
    if (_3886 != 0) {
        _3886 = 1;
        goto LD;
    }
    DeRef(_3880);
    _3880 = (_id == 406);
    _3886 = (_3880 != 0);
LD:
    if (_3886 != 0) {
        goto LE;
    }
    DeRef(_3886);
    _3886 = (_id == 415);
LF:
    if (_3886 == 0)
        goto L10;
LE:

    // 		SubProg(id, 1)
    _15SubProg(_id, 1);
    goto L5;
L10:

    // 		if id = VARIABLE or id = QUALIFIED_VARIABLE then
    DeRef(_3886);
    _3886 = (_id == -100);
    if (_3886 != 0) {
        goto L11;
    }
    DeRef(_3880);
    _3880 = (_id == 515);
L12:
    if (_3880 == 0)
        goto L13;
L11:

    // 		    UndefinedVar(tok[T_SYM])
    DeRef(_3880);
    _2 = (int)SEQ_PTR(_tok);
    _3880 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3880);
    Ref(_3880);
    _15UndefinedVar(_3880);
L13:

    // 		CompileErr(
    RefDS(_3908);
    _6CompileErr(_3908);
L14:
    goto L5;
LA:

    // 	elsif id = TYPE or id = QUALIFIED_TYPE then
    DeRef(_3880);
    _3880 = (_id == 504);
    if (_3880 != 0) {
        goto L15;
    }
    DeRef(_3886);
    _3886 = (_id == 526);
L16:
    if (_3886 == 0)
        goto L17;
L15:

    // 	    Global_declaration(tok[T_SYM], 0)
    DeRef(_3886);
    _2 = (int)SEQ_PTR(_tok);
    _3886 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3886);
    Ref(_3886);
    _15Global_declaration(_3886, 0);
    goto L5;
L17:

    // 	elsif id = CONSTANT then
    if (_id != 416)
        goto L18;

    // 	    Global_declaration(0, 0)
    _15Global_declaration(0, 0);

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L18:

    // 	elsif id = IF then
    if (_id != 20)
        goto L19;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    If_statement()
    _15If_statement();

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L19:

    // 	elsif id = FOR then
    if (_id != 21)
        goto L1A;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    For_statement()
    _15For_statement();

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L1A:

    // 	elsif id = WHILE then
    if (_id != 47)
        goto L1B;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    While_statement()
    _15While_statement();

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L1B:

    // 	elsif id = PROC or id = QUALIFIED_PROC then
    DeRef(_3886);
    _3886 = (_id == 27);
    if (_3886 != 0) {
        goto L1C;
    }
    DeRef(_3880);
    _3880 = (_id == 525);
L1D:
    if (_3880 == 0)
        goto L1E;
L1C:

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Procedure_call(tok)
    RefDS(_tok);
    _15Procedure_call(_tok);

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L1E:

    // 	elsif id = FUNC or id = QUALIFIED_FUNC then
    DeRef(_3880);
    _3880 = (_id == 501);
    if (_3880 != 0) {
        goto L1F;
    }
    DeRef(_3886);
    _3886 = (_id == 524);
L20:
    if (_3886 == 0)
        goto L21;
L1F:

    // 	    CompileErr("function result must be assigned or used")
    RefDS(_3923);
    _6CompileErr(_3923);
    goto L5;
L21:

    // 	elsif id = RETURN then
    if (_id != 412)
        goto L22;

    // 	    Return_statement() -- will fail - not allowed at top level
    _15Return_statement();
    goto L5;
L22:

    // 	elsif id = EXIT then
    if (_id != 61)
        goto L23;

    // 	    CompileErr("exit must be inside a loop")                 
    RefDS(_3926);
    _6CompileErr(_3926);
    goto L5;
L23:

    // 	elsif id = INCLUDE then
    if (_id != 417)
        goto L24;

    // 	    IncludeScan()
    _11IncludeScan();
    goto L5;
L24:

    // 	elsif id = WITH then
    if (_id != 419)
        goto L25;

    // 	    SetWith(TRUE)
    _15SetWith(1);
    goto L5;
L25:

    // 	elsif id = WITHOUT then
    if (_id != 420)
        goto L26;

    // 	    SetWith(FALSE)
    _15SetWith(0);
    goto L5;
L26:

    // 	elsif id = END_OF_FILE then
    if (_id != -21)
        goto L27;

    // 	    if IncludePop() then
    _0 = _3886;
    _3886 = _11IncludePop();
    DeRef(_0);
    if (_3886 == 0)
        goto L28;

    // 		read_line()
    _11read_line();
    goto L5;
L29:

    // 		exit -- all finished
    goto L28;
L2A:
    goto L5;
L27:

    // 	elsif id = QUESTION_MARK then
    if (_id != -31)
        goto L2B;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Print_statement()
    _15Print_statement();

    // 	    ExecCommand()
    _15ExecCommand();
    goto L5;
L2B:

    // 	elsif id = ILLEGAL_CHAR then
    if (_id != -20)
        goto L2C;

    // 	    CompileErr("illegal character")
    RefDS(_3934);
    _6CompileErr(_3934);
    goto L5;
L2C:

    // 	    CompileErr("unknown command")
    RefDS(_3935);
    _6CompileErr(_3935);
L5:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     end while 
    goto L1;
L28:

    //     emit_op(RETURNT)
    _14emit_op(34);

    //     StraightenBranches()
    _15StraightenBranches();

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

    //     EndLineTable()
    _15EndLineTable();

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

    // end procedure
    DeRef(_tok);
    DeRef(_3886);
    DeRef(_3880);
    return 0;
    ;
}


