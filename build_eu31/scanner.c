// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _11InitLex()
{
    int _1553 = 0;
    int _1546;
    int _1544;
    int _0, _1, _2;
    

    //     gline_number = 0
    _4gline_number = 0;

    //     line_number = 0
    _4line_number = 0;

    //     IncludeStk = {}
    RefDS(_39);
    DeRef(_11IncludeStk);
    _11IncludeStk = _39;

    //     char_class = repeat(ILLEGAL_CHAR, 255)  -- we screen out the 0 character
    DeRefi(_11char_class);
    _11char_class = Repeat(-20, 255);

    //     char_class['0'..'9'] = DIGIT
    assign_slice_seq = (s1_ptr *)&_11char_class;
    AssignSlice(48, 57, -7);

    //     char_class['a'..'z'] = LETTER
    assign_slice_seq = (s1_ptr *)&_11char_class;
    AssignSlice(97, 122, -2);

    //     char_class['A'..'Z'] = LETTER
    assign_slice_seq = (s1_ptr *)&_11char_class;
    AssignSlice(65, 90, -2);

    //     char_class[KEYWORD_BASE+1..KEYWORD_BASE+NUM_KEYWORDS] = KEYWORD
    _1544 = 129;
    _1546 = 152;
    assign_slice_seq = (s1_ptr *)&_11char_class;
    AssignSlice(129, 152, -10);

    //     char_class[BUILTIN_BASE+1..BUILTIN_BASE+NUM_BUILTINS] = BUILTIN
    _1546 = 171;
    _1544 = 234;
    assign_slice_seq = (s1_ptr *)&_11char_class;
    AssignSlice(171, 234, -9);

    //     char_class[' '] = BLANK
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 32);
    *(int *)_2 = -8;

    //     char_class['\t'] = BLANK
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 9);
    *(int *)_2 = -8;

    //     char_class['+'] = PLUS
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 43);
    *(int *)_2 = 11;

    //     char_class['-'] = MINUS
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 45);
    *(int *)_2 = 10;

    //     char_class['*'] = MULTIPLY
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 42);
    *(int *)_2 = 13;

    //     char_class['/'] = DIVIDE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 47);
    *(int *)_2 = 14;

    //     char_class['='] = EQUALS
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 61);
    *(int *)_2 = 3;

    //     char_class['<'] = LESS
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 60);
    *(int *)_2 = 1;

    //     char_class['>'] = GREATER
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 62);
    *(int *)_2 = 6;

    //     char_class['\''] = SINGLE_QUOTE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 39);
    *(int *)_2 = -5;

    //     char_class['"'] = DOUBLE_QUOTE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 34);
    *(int *)_2 = -4;

    //     char_class['.'] = DOT
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 46);
    *(int *)_2 = -3;

    //     char_class[':'] = COLON
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 58);
    *(int *)_2 = -23;

    //     char_class['\r'] = NEWLINE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 13);
    *(int *)_2 = -6;

    //     char_class['\n'] = NEWLINE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 10);
    *(int *)_2 = -6;

    //     char_class['!'] = BANG
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 33);
    *(int *)_2 = -1;

    //     char_class['{'] = LEFT_BRACE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 123);
    *(int *)_2 = -24;

    //     char_class['}'] = RIGHT_BRACE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 125);
    *(int *)_2 = -25;

    //     char_class['('] = LEFT_ROUND
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 40);
    *(int *)_2 = -26;

    //     char_class[')'] = RIGHT_ROUND
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 41);
    *(int *)_2 = -27;

    //     char_class['['] = LEFT_SQUARE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 91);
    *(int *)_2 = -28;

    //     char_class[']'] = RIGHT_SQUARE
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 93);
    *(int *)_2 = -29;

    //     char_class['$'] = DOLLAR
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 36);
    *(int *)_2 = -22;

    //     char_class[','] = COMMA
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 44);
    *(int *)_2 = -30;

    //     char_class['&'] = CONCAT
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 38);
    *(int *)_2 = 15;

    //     char_class['?'] = QUESTION_MARK
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 63);
    *(int *)_2 = -31;

    //     char_class['#'] = NUMBER_SIGN
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 35);
    *(int *)_2 = -11;

    //     char_class[END_OF_FILE_CHAR] = END_OF_FILE 
    _2 = (int)SEQ_PTR(_11char_class);
    _2 = (int)(((s1_ptr)_2)->base + 26);
    *(int *)_2 = -21;

    //     id_char = repeat(FALSE, 255)
    DeRefi(_11id_char);
    _11id_char = Repeat(0, 255);

    //     for i = 1 to 255 do
    { int _i;
        _i = 1;
L1:
        if (_i > 255)
            goto L2;

        // 	if i = '_' or find(char_class[i], {LETTER, DIGIT}) then
        _1544 = (_i == 95);
        if (_1544 != 0) {
            goto L3;
        }
        _2 = (int)SEQ_PTR(_11char_class);
        _1546 = (int)*(((s1_ptr)_2)->base + _i);
        DeRef(_1553);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = -2;
        ((int *)_2)[2] = -7;
        _1553 = MAKE_SEQ(_1);
        _0 = _1553;
        _1553 = find(_1546, _1553);
        DeRefDSi(_0);
L4:
        if (_1553 == 0)
            goto L5;
L3:

        // 	    id_char[i] = TRUE
        _2 = (int)SEQ_PTR(_11id_char);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = 1;
L5:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef(_1553);
    return 0;
    ;
}


int _11ResetTP()
{
    int _0, _1, _2;
    

    //     OpTrace = FALSE
    _4OpTrace = 0;

    //     OpProfileStatement = FALSE
    _4OpProfileStatement = 0;

    //     OpProfileTime = FALSE
    _4OpProfileTime = 0;

    //     AnyStatementProfile = FALSE
    _11AnyStatementProfile = 0;

    //     AnyTimeProfile = FALSE
    _11AnyTimeProfile = 0;

    // end procedure
    return 0;
    ;
}


int _11pack_source(int _src)
{
    int _start;
    int _1556 = 0;
    int _0, _1, _2;
    

    //     if equal(src, 0) then
    if (_src == 0)
        _1556 = 1;
    else if (IS_ATOM_INT(_src) && IS_ATOM_INT(0))
        _1556 = 0;
    else
        _1556 = (compare(_src, 0) == 0);
    if (_1556 == 0)
        goto L1;

    // 	return 0
    DeRefi(_src);
    return 0;
L1:

    //     if length(src) >= SOURCE_CHUNK then
    DeRef(_1556);
    _1556 = SEQ_PTR(_src)->length;
    if (_1556 < 10000)
        goto L2;

    // 	src = src[1..80] -- enough for trace or profile display
    rhs_slice_target = (object_ptr)&_src;
    RHS_Slice((s1_ptr)_src, 1, 80);
L2:

    //     if current_source_next + length(src) >= SOURCE_CHUNK then
    DeRef(_1556);
    _1556 = SEQ_PTR(_src)->length;
    _1556 = _11current_source_next + _1556;
    if ((long)((unsigned long)_1556 + (unsigned long)HIGH_BITS) >= 0) 
        _1556 = NewDouble((double)_1556);
    if (binary_op_a(LESS, _1556, 10000))
        goto L3;

    // 	current_source = allocate(SOURCE_CHUNK)
    _0 = _7allocate(10000);
    DeRef(_11current_source);
    _11current_source = _0;

    // 	if current_source = 0 then
    if (binary_op_a(NOTEQ, _11current_source, 0))
        goto L4;

    // 	    CompileErr("out of memory - turn off trace and profile")
    RefDS(_1565);
    _6CompileErr(_1565);
L4:

    // 	all_source = append(all_source, current_source)
    Ref(_11current_source);
    Append(&_11all_source, _11all_source, _11current_source);

    // 	current_source_next = 1 
    _11current_source_next = 1;
L3:

    //     start = current_source_next 
    _start = _11current_source_next;

    //     poke(current_source+current_source_next, src)
    DeRef(_1556);
    if (IS_ATOM_INT(_11current_source)) {
        _1556 = _11current_source + _11current_source_next;
        if ((long)((unsigned long)_1556 + (unsigned long)HIGH_BITS) >= 0) 
            _1556 = NewDouble((double)_1556);
    }
    else {
        _1556 = NewDouble(DBL_PTR(_11current_source)->dbl + (double)_11current_source_next);
    }
    if (IS_ATOM_INT(_1556))
        poke_addr = (unsigned char *)_1556;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_1556)->dbl);
    if (IS_ATOM_INT(_src)) {
        *poke_addr = (unsigned char)_src;
    }
    else if (IS_ATOM(_src)) {
        *poke_addr = (signed char)DBL_PTR(_src)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_src);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *poke_addr++ = (unsigned char)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
            }
        }
    }

    //     current_source_next += length(src)-1
    DeRef(_1556);
    _1556 = SEQ_PTR(_src)->length;
    _1556 = _1556 - 1;
    _11current_source_next = _11current_source_next + _1556;

    //     poke(current_source+current_source_next, 0) -- overwrite \n
    if (IS_ATOM_INT(_11current_source)) {
        _1556 = _11current_source + _11current_source_next;
        if ((long)((unsigned long)_1556 + (unsigned long)HIGH_BITS) >= 0) 
            _1556 = NewDouble((double)_1556);
    }
    else {
        _1556 = NewDouble(DBL_PTR(_11current_source)->dbl + (double)_11current_source_next);
    }
    if (IS_ATOM_INT(_1556))
        poke_addr = (unsigned char *)_1556;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_1556)->dbl);
    *poke_addr = (unsigned char)0;

    //     current_source_next += 1
    _11current_source_next = _11current_source_next + 1;

    //     return start + SOURCE_CHUNK * (length(all_source)-1)
    DeRef(_1556);
    _1556 = SEQ_PTR(_11all_source)->length;
    _1556 = _1556 - 1;
    if (_1556 <= INT15)
        _1556 = 10000 * _1556;
    else
        _1556 = NewDouble(10000 * (double)_1556);
    _0 = _1556;
    if (IS_ATOM_INT(_1556)) {
        _1556 = _start + _1556;
        if ((long)((unsigned long)_1556 + (unsigned long)HIGH_BITS) >= 0) 
            _1556 = NewDouble((double)_1556);
    }
    else {
        _1556 = NewDouble((double)_start + DBL_PTR(_1556)->dbl);
    }
    DeRef(_0);
    DeRefi(_src);
    return _1556;
    ;
}


int _11fetch_line(int _start)
{
    int _line = 0;
    int _c;
    int _chunk;
    int _p = 0;
    int _1577 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_start)) {
        _1 = (long)(DBL_PTR(_start)->dbl);
        DeRefDS(_start);
        _start = _1;
    }

    //     if start = 0 then
    if (_start != 0)
        goto L1;

    // 	return ""
    RefDS(_39);
    return _39;
L1:

    //     line = ""
    RefDS(_39);
    DeRefi(_line);
    _line = _39;

    //     chunk = 1+floor(start / SOURCE_CHUNK)
    DeRef(_1577);
    if (10000 > 0 && _start >= 0) {
        _1577 = _start / 10000;
    }
    else {
        temp_dbl = floor((double)_start / (double)10000);
        _1577 = (long)temp_dbl;
    }
    _chunk = _1577 + 1;

    //     start = remainder(start, SOURCE_CHUNK)
    _start = (_start % 10000);

    //     p = all_source[chunk] + start
    _2 = (int)SEQ_PTR(_11all_source);
    _1577 = (int)*(((s1_ptr)_2)->base + _chunk);
    Ref(_1577);
    DeRef(_p);
    if (IS_ATOM_INT(_1577)) {
        _p = _1577 + _start;
        if ((long)((unsigned long)_p + (unsigned long)HIGH_BITS) >= 0) 
            _p = NewDouble((double)_p);
    }
    else {
        _p = NewDouble(DBL_PTR(_1577)->dbl + (double)_start);
    }

    //     while TRUE do
L2:

    // 	c = peek(p)
    if (IS_ATOM_INT(_p)) {
        _c = *(unsigned char *)_p;
    }
    else {
        _c = *(unsigned char *)(unsigned long)(DBL_PTR(_p)->dbl);
    }

    // 	if c = 0 then
    if (_c != 0)
        goto L3;

    // 	    exit
    goto L4;
L3:

    // 	line &= c
    Append(&_line, _line, _c);

    // 	p += 1
    _0 = _p;
    if (IS_ATOM_INT(_p)) {
        _p = _p + 1;
        if (_p > MAXINT)
            _p = NewDouble((double)_p);
    }
    else
        _p = binary_op(PLUS, 1, _p);
    DeRef(_0);

    //     end while
    goto L2;
L4:

    //     return line
    DeRef(_p);
    DeRef(_1577);
    return _line;
    ;
}


int _11AppendSourceLine()
{
    int _new = 0;
    int _old = 0;
    int _options;
    int _src = 0;
    int _1609 = 0;
    int _1587 = 0;
    int _1604 = 0;
    int _0, _1, _2;
    

    //     src = 0
    _src = 0;

    //     options = 0
    _options = 0;

    //     if TRANSLATE or OpTrace or OpProfileStatement or OpProfileTime then
    if (0 != 0) {
        _1587 = 1;
        goto L1;
    }
    _1587 = (_4OpTrace != 0);
L1:
    if (_1587 != 0) {
        DeRef(_1587);
        _1587 = 1;
        goto L2;
    }
    _1587 = (_4OpProfileStatement != 0);
L2:
    if (_1587 != 0) {
        goto L3;
    }
L4:
    if (_4OpProfileTime == 0)
        goto L5;
L3:

    // 	src = ThisLine
    Ref(_6ThisLine);
    DeRefi(_src);
    _src = _6ThisLine;

    // 	if ELINUX and TRANSLATE and mybsd then
    if (_4ELINUX == 0) {
        DeRef(_1587);
        _1587 = 0;
        goto L6;
    }
    _1587 = (0 != 0);
L6:
    if (_1587 == 0) {
        goto L7;
    }
L8:
    if (_4mybsd == 0)
        goto L7;

    // 	    src = ""  -- save space, only 8Mb available!
    RefDS(_39);
    DeRefi(_src);
    _src = _39;
L7:

    // 	if OpTrace then
    if (_4OpTrace == 0)
        goto L9;

    // 	    options = SOP_TRACE
    _options = 1;
L9:

    // 	if OpProfileTime then
    if (_4OpProfileTime == 0)
        goto LA;

    // 	    options = or_bits(options, SOP_PROFILE_TIME)
    _options = (_options | 2);
LA:

    // 	if OpProfileStatement then
    if (_4OpProfileStatement == 0)
        goto LB;

    // 	    options = or_bits(options, SOP_PROFILE_STATEMENT)
    _options = (_options | 4);
LB:

    // 	if OpProfileStatement or OpProfileTime then
    if (_4OpProfileStatement != 0) {
        goto LC;
    }
LD:
    if (_4OpProfileTime == 0)
        goto LE;
LC:

    // 	    src = {0,0,0,0} & src
    _0 = _1587;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 0;
    *((int *)(_2+8)) = 0;
    *((int *)(_2+12)) = 0;
    *((int *)(_2+16)) = 0;
    _1587 = MAKE_SEQ(_1);
    DeRef(_0);
    if (IS_SEQUENCE(_1587) && IS_ATOM(_src)) {
        Ref(_src);
        Append(&_src, _1587, _src);
    }
    else if (IS_ATOM(_1587) && IS_SEQUENCE(_src)) {
    }
    else {
        Concat((object_ptr)&_src, _1587, (s1_ptr)_src);
    }
LE:
L5:

    //     if length(slist) then
    DeRef(_1587);
    _1587 = SEQ_PTR(_4slist)->length;
    if (_1587 == 0)
        goto LF;

    // 	old = slist[$-1]
    _1587 = SEQ_PTR(_4slist)->length;
    _1587 = _1587 - 1;
    DeRef(_old);
    _2 = (int)SEQ_PTR(_4slist);
    _old = (int)*(((s1_ptr)_2)->base + _1587);
    Ref(_old);

    // 	if equal(src, old[SRC]) and 
    _2 = (int)SEQ_PTR(_old);
    _1587 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1587);
    _0 = _1587;
    if (_src == _1587)
        _1587 = 1;
    else if (IS_ATOM_INT(_src) && IS_ATOM_INT(_1587))
        _1587 = 0;
    else
        _1587 = (compare(_src, _1587) == 0);
    DeRef(_0);
    if (_1587 == 0) {
        _1587 = 0;
        goto L10;
    }
    DeRef(_1604);
    _2 = (int)SEQ_PTR(_old);
    _1604 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1604);
    _0 = _1604;
    if (IS_ATOM_INT(_1604)) {
        _1604 = (_4current_file_no == _1604);
    }
    else {
        _1604 = binary_op(EQUALS, _4current_file_no, _1604);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1604))
        _1587 = (_1604 != 0);
    else
        _1587 = DBL_PTR(_1604)->dbl != 0.0;
L10:
    if (_1587 == 0) {
        DeRef(_1604);
        _1604 = 0;
        goto L11;
    }
    DeRef(_1587);
    _2 = (int)SEQ_PTR(_old);
    _1587 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1587);
    _0 = _1587;
    if (IS_ATOM_INT(_1587)) {
        _1587 = _1587 + 1;
        if (_1587 > MAXINT)
            _1587 = NewDouble((double)_1587);
    }
    else
        _1587 = binary_op(PLUS, 1, _1587);
    DeRef(_0);
    DeRef(_1609);
    _1609 = SEQ_PTR(_4slist)->length;
    _2 = (int)SEQ_PTR(_4slist);
    _1609 = (int)*(((s1_ptr)_2)->base + _1609);
    Ref(_1609);
    _0 = _1609;
    if (IS_ATOM_INT(_1587) && IS_ATOM_INT(_1609)) {
        _1609 = _1587 + _1609;
        if ((long)((unsigned long)_1609 + (unsigned long)HIGH_BITS) >= 0) 
            _1609 = NewDouble((double)_1609);
    }
    else {
        _1609 = binary_op(PLUS, _1587, _1609);
    }
    DeRef(_0);
    _0 = _1609;
    if (IS_ATOM_INT(_1609)) {
        _1609 = (_4line_number == _1609);
    }
    else {
        _1609 = binary_op(EQUALS, _4line_number, _1609);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1609))
        _1604 = (_1609 != 0);
    else
        _1604 = DBL_PTR(_1609)->dbl != 0.0;
L11:
    if (_1604 == 0) {
        goto L12;
    }
    DeRef(_1587);
    _2 = (int)SEQ_PTR(_old);
    _1587 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_1587);
    _0 = _1587;
    if (IS_ATOM_INT(_1587)) {
        _1587 = (_options == _1587);
    }
    else {
        _1587 = binary_op(EQUALS, _options, _1587);
    }
    DeRef(_0);
L13:
    if (_1587 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_1587) && DBL_PTR(_1587)->dbl == 0.0)
            goto L12;
    }

    // 	    slist[$] += 1  
    DeRef(_1587);
    _1587 = SEQ_PTR(_4slist)->length;
    DeRef(_1609);
    _2 = (int)SEQ_PTR(_4slist);
    _1609 = (int)*(((s1_ptr)_2)->base + _1587);
    Ref(_1609);
    _0 = _1609;
    if (IS_ATOM_INT(_1609)) {
        _1609 = _1609 + 1;
        if (_1609 > MAXINT)
            _1609 = NewDouble((double)_1609);
    }
    else
        _1609 = binary_op(PLUS, 1, _1609);
    DeRef(_0);
    Ref(_1609);
    _2 = (int)SEQ_PTR(_4slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4slist = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _1587);
    _1 = *(int *)_2;
    *(int *)_2 = _1609;
    DeRef(_1);
    goto L14;
L12:

    // 	    src = pack_source(src)
    Ref(_src);
    _0 = _src;
    _src = _11pack_source(_src);
    DeRefi(_0);

    // 	    new = {src, line_number, current_file_no, options}
    _0 = _new;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_src);
    *((int *)(_2+4)) = _src;
    *((int *)(_2+8)) = _4line_number;
    *((int *)(_2+12)) = _4current_file_no;
    *((int *)(_2+16)) = _options;
    _new = MAKE_SEQ(_1);
    DeRef(_0);

    // 	    if slist[$] = 0 then
    DeRef(_1609);
    _1609 = SEQ_PTR(_4slist)->length;
    _2 = (int)SEQ_PTR(_4slist);
    _1609 = (int)*(((s1_ptr)_2)->base + _1609);
    Ref(_1609);
    if (binary_op_a(NOTEQ, _1609, 0))
        goto L15;

    // 		slist[$] = new
    DeRef(_1609);
    _1609 = SEQ_PTR(_4slist)->length;
    RefDS(_new);
    _2 = (int)SEQ_PTR(_4slist);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4slist = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _1609);
    _1 = *(int *)_2;
    *(int *)_2 = _new;
    DeRef(_1);
    goto L16;
L15:

    // 		slist = append(slist, new)
    RefDS(_new);
    Append(&_4slist, _4slist, _new);
L16:

    // 	    slist = append(slist, 0)
    Append(&_4slist, _4slist, 0);
L17:
    goto L14;
LF:

    // 	src = pack_source(src)
    Ref(_src);
    _0 = _src;
    _src = _11pack_source(_src);
    DeRefi(_0);

    // 	slist = {{src, line_number, current_file_no, options}, 0}
    _0 = _1609;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_src);
    *((int *)(_2+4)) = _src;
    *((int *)(_2+8)) = _4line_number;
    *((int *)(_2+12)) = _4current_file_no;
    *((int *)(_2+16)) = _options;
    _1609 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_4slist);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _1609;
    RefDS(_1609);
    ((int *)_2)[2] = 0;
    _4slist = MAKE_SEQ(_1);
L14:

    // end procedure
    DeRef(_new);
    DeRef(_old);
    DeRefi(_src);
    DeRef(_1609);
    DeRef(_1587);
    DeRef(_1604);
    return 0;
    ;
}


int _11s_expand(int _slist)
{
    int _new_slist = 0;
    int _1639 = 0;
    int _1636;
    int _1631 = 0;
    int _1630;
    int _0, _1, _2, _3;
    

    //     new_slist = {}
    RefDS(_39);
    _new_slist = _39;

    //     for i = 1 to length(slist) do
    _1630 = SEQ_PTR(_slist)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _1630)
            goto L2;

        // 	if sequence(slist[i]) then
        DeRef(_1631);
        _2 = (int)SEQ_PTR(_slist);
        _1631 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1631);
        _0 = _1631;
        _1631 = IS_SEQUENCE(_1631);
        DeRef(_0);
        if (_1631 == 0)
            goto L3;

        // 	    new_slist = append(new_slist, slist[i])
        _2 = (int)SEQ_PTR(_slist);
        _1631 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1631);
        Ref(_1631);
        Append(&_new_slist, _new_slist, _1631);
        goto L4;
L3:

        // 	    for j = 1 to slist[i] do
        DeRef(_1631);
        _2 = (int)SEQ_PTR(_slist);
        _1631 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1631);
        { int _j;
            _j = 1;
L5:
            if (binary_op_a(GREATER, _j, _1631))
                goto L6;

            // 		slist[i-1][LINE] += 1
            _1636 = _i - 1;
            _2 = (int)SEQ_PTR(_slist);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _slist = MAKE_SEQ(_2);
            }
            _3 = (int)(_1636 + ((s1_ptr)_2)->base);
            DeRef(_1639);
            _2 = (int)SEQ_PTR(*(int *)_3);
            _1639 = (int)*(((s1_ptr)_2)->base + 2);
            Ref(_1639);
            _0 = _1639;
            if (IS_ATOM_INT(_1639)) {
                _1639 = _1639 + 1;
                if (_1639 > MAXINT)
                    _1639 = NewDouble((double)_1639);
            }
            else
                _1639 = binary_op(PLUS, 1, _1639);
            DeRef(_0);
            Ref(_1639);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 2);
            _1 = *(int *)_2;
            *(int *)_2 = _1639;
            DeRef(_1);

            // 		new_slist = append(new_slist, slist[i-1]) 
            DeRef(_1639);
            _1639 = _i - 1;
            _2 = (int)SEQ_PTR(_slist);
            _1639 = (int)*(((s1_ptr)_2)->base + _1639);
            Ref(_1639);
            Ref(_1639);
            Append(&_new_slist, _new_slist, _1639);

            // 	    end for
            _0 = _j;
            if (IS_ATOM_INT(_j)) {
                _j = _j + 1;
                if ((long)((unsigned long)_j +(unsigned long) HIGH_BITS) >= 0) 
                    _j = NewDouble((double)_j);
            }
            else {
                _j = binary_op_a(PLUS, _j, 1);
            }
            DeRef(_0);
            goto L5;
L6:
            ;
            DeRef(_j);
        }
L4:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return new_slist
    DeRefDS(_slist);
    DeRef(_1639);
    DeRef(_1631);
    return _new_slist;
    ;
}


int _11read_line()
{
    int _n;
    int _1644;
    int _0, _1, _2;
    

    //     line_number += 1
    _4line_number = _4line_number + 1;

    //     gline_number += 1
    _4gline_number = _4gline_number + 1;

    //     ThisLine = gets(src_file)
    DeRefi(_6ThisLine);
    _6ThisLine = EGets(_11src_file);

    //     if atom(ThisLine) then
    _1644 = IS_ATOM(_6ThisLine);
    if (_1644 == 0)
        goto L1;

    // 	ThisLine = {END_OF_FILE_CHAR}
    RefDS(_1648);
    DeRefi(_6ThisLine);
    _6ThisLine = _1648;
L1:

    //     bp = 1
    _6bp = 1;

    //     n = length(ThisLine)
    _n = SEQ_PTR(_6ThisLine)->length;

    //     if ThisLine[n] != '\n' then
    _2 = (int)SEQ_PTR(_6ThisLine);
    _1644 = (int)*(((s1_ptr)_2)->base + _n);
    if (_1644 == 10)
        goto L2;

    // 	ThisLine = append(ThisLine, '\n') -- add missing \n (might happen at end of file)
    Append(&_6ThisLine, _6ThisLine, 10);
L2:

    //     AppendSourceLine()
    _11AppendSourceLine();

    // end procedure
    return 0;
    ;
}


int _11bad_zero()
{
    int _0, _1, _2;
    

    //     CompileErr("illegal character (ASCII 0)")
    RefDS(_1653);
    _6CompileErr(_1653);

    // end procedure
    return 0;
    ;
}


int _11getch()
{
    int _c;
    int _0, _1, _2;
    

    //     c = ThisLine[bp]
    _2 = (int)SEQ_PTR(_6ThisLine);
    _c = (int)*(((s1_ptr)_2)->base + _6bp);

    //     if c = 0 then
    if (_c != 0)
        goto L1;

    // 	bad_zero()
    _11bad_zero();
L1:

    //     bp += 1
    _6bp = _6bp + 1;

    //     return c   
    return _c;
    ;
}


int _11ungetch()
{
    int _0, _1, _2;
    

    //     bp -= 1               
    _6bp = _6bp - 1;

    // end procedure
    return 0;
    ;
}


int _11get_file_path(int _s)
{
    int _1658 = 0;
    int _0, _1, _2;
    

    // 	for t=length(s) to 1 by -1 do
    _1658 = SEQ_PTR(_s)->length;
    { int _t;
        _t = _1658;
L1:
        if (_t < 1)
            goto L2;

        // 		if find(s[t],SLASH_CHARS) then
        DeRef(_1658);
        _2 = (int)SEQ_PTR(_s);
        _1658 = (int)*(((s1_ptr)_2)->base + _t);
        Ref(_1658);
        _0 = _1658;
        _1658 = find(_1658, _4SLASH_CHARS);
        DeRef(_0);
        if (_1658 == 0)
            goto L3;

        // 			return s[1..t]
        rhs_slice_target = (object_ptr)&_1658;
        RHS_Slice((s1_ptr)_s, 1, _t);
        DeRefDS(_s);
        return _1658;
L3:

        // 	end for
        _t = _t + -1;
        goto L1;
L2:
        ;
    }

    // 	return "." & SLASH
    Append(&_1658, _1517, _4SLASH);
    DeRefDS(_s);
    return _1658;
    ;
}


int _11path_open()
{
    int _absolute;
    int _try97531;
    int _full_path = 0;
    int _inc_path = 0;
    int _errbuff = 0;
    int _currdir = 0;
    int _1666 = 0;
    int _1663 = 0;
    int _1697 = 0;
    int _1665;
    int _0, _1, _2;
    

    //     absolute = FALSE
    _absolute = 0;

    //     absolute = find(new_include_name[1], SLASH_CHARS) or
    _2 = (int)SEQ_PTR(_11new_include_name);
    _1663 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1663);
    _0 = _1663;
    _1663 = find(_1663, _4SLASH_CHARS);
    DeRef(_0);
    _1665 = (_4ELINUX == 0);
    _1666 = find(58, _11new_include_name);
    _1666 = (_1665 != 0 && _1666 != 0);
    _absolute = (_1663 != 0 || _1666 != 0);

    //     if absolute then
    if (_absolute == 0)
        goto L1;

    // 		try = open(new_include_name, "r")
    _try97531 = EOpen(_11new_include_name, _1669);

    // 		if try = -1 then
    if (_try97531 != -1)
        goto L2;

    // 		    errbuff = sprintf("can't open %s", new_include_name)
    _errbuff = EPrintf(-9999999, _1672, _11new_include_name);

    // 		    CompileErr(errbuff)
    RefDS(_errbuff);
    _6CompileErr(_errbuff);
L2:

    // 		return try
    DeRef(_full_path);
    DeRefi(_inc_path);
    DeRefi(_errbuff);
    DeRef(_currdir);
    DeRef(_1666);
    DeRef(_1663);
    DeRef(_1697);
    return _try97531;
L1:

    //     currdir = get_file_path( file_name[current_file_no] )
    DeRef(_1666);
    _2 = (int)SEQ_PTR(_4file_name);
    _1666 = (int)*(((s1_ptr)_2)->base + _4current_file_no);
    RefDS(_1666);
    RefDS(_1666);
    _0 = _currdir;
    _currdir = _11get_file_path(_1666);
    DeRef(_0);

    //     full_path = currdir & new_include_name
    Concat((object_ptr)&_full_path, _currdir, (s1_ptr)_11new_include_name);

    //     try = open(full_path, "r")
    _try97531 = EOpen(_full_path, _1669);

    //     if try = -1 then
    if (_try97531 != -1)
        goto L3;

    // 	full_path = main_path & new_include_name
    Concat((object_ptr)&_full_path, _11main_path, (s1_ptr)_11new_include_name);

    // 	try = open(full_path,  "r")
    _try97531 = EOpen(_full_path, _1669);
L3:

    //     if try = -1 then
    if (_try97531 != -1)
        goto L4;

    // 	inc_path = getenv("EUINC")
    DeRefi(_inc_path);
    _inc_path = EGetEnv(_1682);

    // 	if sequence(inc_path) and length(inc_path) > 0 then  
    DeRef(_1666);
    _1666 = IS_SEQUENCE(_inc_path);
    if (_1666 == 0) {
        goto L5;
    }
    _1665 = SEQ_PTR(_inc_path)->length;
    _1665 = (_1665 > 0);
L6:
    if (_1665 == 0)
        goto L5;

    // 	    inc_path = append(inc_path, PATH_SEPARATOR)
    Append(&_inc_path, _inc_path, _4PATH_SEPARATOR);

    // 	    full_path = ""
    RefDS(_39);
    DeRef(_full_path);
    _full_path = _39;

    // 	    for p = 1 to length(inc_path) do
    _1665 = SEQ_PTR(_inc_path)->length;
    { int _p;
        _p = 1;
L7:
        if (_p > _1665)
            goto L8;

        // 		if inc_path[p] = PATH_SEPARATOR then
        DeRef(_1666);
        _2 = (int)SEQ_PTR(_inc_path);
        _1666 = (int)*(((s1_ptr)_2)->base + _p);
        if (_1666 != _4PATH_SEPARATOR)
            goto L9;

        // 		    while length(full_path) and 
LA:
        DeRef(_1666);
        _1666 = SEQ_PTR(_full_path)->length;
        if (_1666 == 0) {
            goto LB;
        }
        DeRef(_1663);
        _1663 = SEQ_PTR(_full_path)->length;
        _2 = (int)SEQ_PTR(_full_path);
        _1663 = (int)*(((s1_ptr)_2)->base + _1663);
        Ref(_1663);
        Concat((object_ptr)&_1697, _1696, (s1_ptr)_4SLASH_CHARS);
        _0 = _1697;
        _1697 = find(_1663, _1697);
        DeRefDSi(_0);
LC:
        if (_1697 == 0)
            goto LB;

        // 			full_path = full_path[1..$-1]
        DeRef(_1697);
        _1697 = SEQ_PTR(_full_path)->length;
        _1697 = _1697 - 1;
        rhs_slice_target = (object_ptr)&_full_path;
        RHS_Slice((s1_ptr)_full_path, 1, _1697);

        // 		    end while
        goto LA;
LB:

        // 		    if length(full_path) then
        DeRef(_1697);
        _1697 = SEQ_PTR(_full_path)->length;
        if (_1697 == 0)
            goto LD;

        // 			full_path = full_path & SLASH & new_include_name
        {
            int concat_list[3];

            concat_list[0] = _11new_include_name;
            concat_list[1] = _4SLASH;
            concat_list[2] = _full_path;
            Concat_N((object_ptr)&_full_path, concat_list, 3);
        }

        // 			try = open(full_path, "r")
        _try97531 = EOpen(_full_path, _1669);

        // 			if try != -1 then
        if (_try97531 == -1)
            goto LE;

        // 			    exit
        goto L8;
LE:

        // 			full_path = ""
        RefDS(_39);
        DeRef(_full_path);
        _full_path = _39;
LF:
        goto LD;
L9:

        // 		    if length(full_path) or 
        DeRef(_1697);
        _1697 = SEQ_PTR(_full_path)->length;
        if (_1697 != 0) {
            goto L10;
        }
        DeRef(_1663);
        _2 = (int)SEQ_PTR(_inc_path);
        _1663 = (int)*(((s1_ptr)_2)->base + _p);
        _1663 = (_1663 != 32);
        if (_1663 == 0) {
            _1663 = 0;
            goto L11;
        }
        DeRef(_1666);
        _2 = (int)SEQ_PTR(_inc_path);
        _1666 = (int)*(((s1_ptr)_2)->base + _p);
        _1666 = (_1666 != 9);
        _1663 = (_1666 != 0);
L11:
L12:
        if (_1663 == 0)
            goto L13;
L10:

        // 			full_path &= inc_path[p]
        DeRef(_1666);
        _2 = (int)SEQ_PTR(_inc_path);
        _1666 = (int)*(((s1_ptr)_2)->base + _p);
        Append(&_full_path, _full_path, _1666);
L13:
LD:

        // 	    end for
        _p = _p + 1;
        goto L7;
L8:
        ;
    }

    // 	    inc_path = inc_path[1..$-1] 
    DeRef(_1666);
    _1666 = SEQ_PTR(_inc_path)->length;
    _1666 = _1666 - 1;
    rhs_slice_target = (object_ptr)&_inc_path;
    RHS_Slice((s1_ptr)_inc_path, 1, _1666);
L5:
L4:

    //     if try = -1 then
    if (_try97531 != -1)
        goto L14;

    // 	full_path = eudir & SLASH & "include" & SLASH & new_include_name
    {
        int concat_list[5];

        concat_list[0] = _11new_include_name;
        concat_list[1] = _4SLASH;
        concat_list[2] = _700;
        concat_list[3] = _4SLASH;
        concat_list[4] = _4eudir;
        Concat_N((object_ptr)&_full_path, concat_list, 5);
    }

    // 	try = open(full_path, "r")
    _try97531 = EOpen(_full_path, _1669);
L14:

    //     if try != -1 then
    if (_try97531 == -1)
        goto L15;

    // 	new_include_name = full_path
    RefDS(_full_path);
    DeRef(_11new_include_name);
    _11new_include_name = _full_path;

    // 	return try
    DeRefDS(_full_path);
    DeRefi(_inc_path);
    DeRefi(_errbuff);
    DeRef(_currdir);
    DeRef(_1666);
    DeRef(_1663);
    DeRef(_1697);
    return _try97531;
L15:

    //     if length(main_path) = 0 then
    DeRef(_1666);
    _1666 = SEQ_PTR(_11main_path)->length;
    if (_1666 != 0)
        goto L16;

    // 	main_path = "."
    RefDS(_1517);
    DeRefDS(_11main_path);
    _11main_path = _1517;
L16:

    //     if find(main_path[$], SLASH_CHARS) then
    DeRef(_1666);
    _1666 = SEQ_PTR(_11main_path)->length;
    _2 = (int)SEQ_PTR(_11main_path);
    _1666 = (int)*(((s1_ptr)_2)->base + _1666);
    Ref(_1666);
    _0 = _1666;
    _1666 = find(_1666, _4SLASH_CHARS);
    DeRef(_0);
    if (_1666 == 0)
        goto L17;

    // 	main_path = main_path[1..$-1]  -- looks better
    _1666 = SEQ_PTR(_11main_path)->length;
    _1666 = _1666 - 1;
    rhs_slice_target = (object_ptr)&_11main_path;
    RHS_Slice((s1_ptr)_11main_path, 1, _1666);
L17:

    //     if atom(inc_path) then
    DeRef(_1666);
    _1666 = IS_ATOM(_inc_path);
    if (_1666 == 0)
        goto L18;

    // 	errbuff = sprintf("can't find %s in %s\nor in %s%sinclude", 
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_11new_include_name);
    *((int *)(_2+4)) = _11new_include_name;
    RefDS(_11main_path);
    *((int *)(_2+8)) = _11main_path;
    Ref(_4eudir);
    *((int *)(_2+12)) = _4eudir;
    *((int *)(_2+16)) = _4SLASH;
    _1666 = MAKE_SEQ(_1);
    DeRefi(_errbuff);
    _errbuff = EPrintf(-9999999, _1731, _1666);
    goto L19;
L18:

    // 	errbuff = sprintf("can't find %s in %s\nor in %s\nor in %s%sinclude", 
    _0 = _1666;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_11new_include_name);
    *((int *)(_2+4)) = _11new_include_name;
    RefDS(_11main_path);
    *((int *)(_2+8)) = _11main_path;
    Ref(_inc_path);
    *((int *)(_2+12)) = _inc_path;
    Ref(_4eudir);
    *((int *)(_2+16)) = _4eudir;
    *((int *)(_2+20)) = _4SLASH;
    _1666 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefi(_errbuff);
    _errbuff = EPrintf(-9999999, _1734, _1666);
L19:

    //     CompileErr(errbuff)
    RefDS(_errbuff);
    _6CompileErr(_errbuff);
    ;
}


int _11same_name(int _a, int _b)
{
    int _1744 = 0;
    int _1737 = 0;
    int _1739;
    int _0, _1, _2;
    

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L1;

    // 	return equal(a, b) -- case sensitive
    if (_a == _b)
        _1737 = 1;
    else if (IS_ATOM_INT(_a) && IS_ATOM_INT(_b))
        _1737 = 0;
    else
        _1737 = (compare(_a, _b) == 0);
    DeRefDS(_a);
    DeRefDS(_b);
    return _1737;
L1:

    //     if length(a) != length(b) then
    DeRef(_1737);
    _1737 = SEQ_PTR(_a)->length;
    _1739 = SEQ_PTR(_b)->length;
    if (_1737 == _1739)
        goto L2;

    // 	return FALSE
    DeRefDS(_a);
    DeRefDS(_b);
    DeRef(_1744);
    return 0;
L2:

    //     for i = 1 to length(a) do
    _1739 = SEQ_PTR(_a)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _1739)
            goto L4;

        // 	if upper(a[i]) != upper(b[i]) then
        DeRef(_1737);
        _2 = (int)SEQ_PTR(_a);
        _1737 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1737);
        Ref(_1737);
        _0 = _1737;
        _1737 = _3upper(_1737);
        DeRef(_0);
        DeRef(_1744);
        _2 = (int)SEQ_PTR(_b);
        _1744 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1744);
        Ref(_1744);
        _0 = _1744;
        _1744 = _3upper(_1744);
        DeRef(_0);
        if (binary_op_a(EQUALS, _1737, _1744))
            goto L5;

        // 	    return FALSE
        DeRefDS(_a);
        DeRefDS(_b);
        DeRef(_1744);
        DeRef(_1737);
        return 0;
L5:

        //     end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    //     return TRUE
    DeRefDS(_a);
    DeRefDS(_b);
    DeRef(_1744);
    DeRef(_1737);
    return 1;
    ;
}


int _11IncludePush()
{
    int _new_file;
    int _new_name = 0;
    int _1755 = 0;
    int _1754 = 0;
    int _1747 = 0;
    int _0, _1, _2, _3;
    

    //     start_include = FALSE
    _11start_include = 0;

    //     new_file = path_open() -- sets new_include_name to full path 
    _new_file = _11path_open();

    //     new_name = name_ext(new_include_name)
    RefDS(_11new_include_name);
    _new_name = _10name_ext(_11new_include_name);

    //     for i = length(file_name) to 1 by -1 do
    _1747 = SEQ_PTR(_4file_name)->length;
    { int _i;
        _i = _1747;
L1:
        if (_i < 1)
            goto L2;

        // 	if same_name(new_name, name_ext(file_name[i])) and
        DeRef(_1747);
        _2 = (int)SEQ_PTR(_4file_name);
        _1747 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_1747);
        RefDS(_1747);
        _0 = _1747;
        _1747 = _10name_ext(_1747);
        DeRefDS(_0);
        RefDS(_new_name);
        RefDS(_1747);
        _0 = _1747;
        _1747 = _11same_name(_new_name, _1747);
        DeRefDS(_0);
        if (_1747 == 0) {
            goto L3;
        }
        RefDS(_11new_include_name);
        _0 = _1754;
        _1754 = _12dir(_11new_include_name);
        DeRef(_0);
        DeRef(_1755);
        _2 = (int)SEQ_PTR(_4file_name);
        _1755 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_1755);
        RefDS(_1755);
        _0 = _1755;
        _1755 = _12dir(_1755);
        DeRefDS(_0);
        _0 = _1755;
        if (_1754 == _1755)
            _1755 = 1;
        else if (IS_ATOM_INT(_1754) && IS_ATOM_INT(_1755))
            _1755 = 0;
        else
            _1755 = (compare(_1754, _1755) == 0);
        DeRef(_0);
L4:
        if (_1755 == 0)
            goto L3;

        // 	    if new_include_space != 0 then
        if (_11new_include_space == 0)
            goto L5;

        // 		SymTab[new_include_space][S_OBJ] = i -- but note any namespace
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_11new_include_space + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = _i;
        DeRef(_1);
L5:

        // 	    close(new_file)
        EClose(_new_file);

        // 	    return -- ignore it  
        DeRef(_new_name);
        DeRef(_1755);
        DeRef(_1754);
        DeRef(_1747);
        return 0;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     if length(IncludeStk) >= INCLUDE_LIMIT then
    DeRef(_1754);
    _1754 = SEQ_PTR(_11IncludeStk)->length;
    if (_1754 < 30)
        goto L6;

    // 	CompileErr("includes are nested too deeply")
    RefDS(_1763);
    _6CompileErr(_1763);
L6:

    //     IncludeStk = append(IncludeStk, 
    _0 = _1754;
    _1 = NewS1(9);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _4current_file_no;
    *((int *)(_2+8)) = _4line_number;
    *((int *)(_2+12)) = _11src_file;
    *((int *)(_2+16)) = _4file_start_sym;
    *((int *)(_2+20)) = _4OpWarning;
    *((int *)(_2+24)) = _4OpTrace;
    *((int *)(_2+28)) = _4OpTypeCheck;
    *((int *)(_2+32)) = _4OpProfileTime;
    *((int *)(_2+36)) = _4OpProfileStatement;
    _1754 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_1754);
    Append(&_11IncludeStk, _11IncludeStk, _1754);

    //     src_file = new_file
    _11src_file = _new_file;

    //     file_start_sym = last_sym
    _4file_start_sym = _10last_sym;

    //     if current_file_no >= MAX_FILE then
    if (_4current_file_no < 256)
        goto L7;

    // 	CompileErr("program includes too many files")
    RefDS(_1767);
    _6CompileErr(_1767);
L7:

    //     file_name = append(file_name, new_include_name)
    RefDS(_11new_include_name);
    Append(&_4file_name, _4file_name, _11new_include_name);

    //     current_file_no = length(file_name)
    _4current_file_no = SEQ_PTR(_4file_name)->length;

    //     if new_include_space != 0 then
    if (_11new_include_space == 0)
        goto L8;

    // 	SymTab[new_include_space][S_OBJ] = current_file_no
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_11new_include_space + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4current_file_no;
    DeRef(_1);
L8:

    //     line_number = 0
    _4line_number = 0;

    // end procedure
    DeRef(_new_name);
    DeRef(_1755);
    DeRef(_1754);
    DeRef(_1747);
    return 0;
    ;
}


int _11IncludePop()
{
    int _top = 0;
    int _1773;
    int _0, _1, _2;
    

    //     HideLocals()
    _10HideLocals();

    //     close(src_file)
    EClose(_11src_file);

    //     if length(IncludeStk) = 0 then 
    _1773 = SEQ_PTR(_11IncludeStk)->length;
    if (_1773 != 0)
        goto L1;

    // 	return FALSE  -- the end  
    return 0;
L1:

    //     top = IncludeStk[$]
    _1773 = SEQ_PTR(_11IncludeStk)->length;
    DeRef(_top);
    _2 = (int)SEQ_PTR(_11IncludeStk);
    _top = (int)*(((s1_ptr)_2)->base + _1773);
    RefDS(_top);

    //     current_file_no    = top[FILE_NO]
    _2 = (int)SEQ_PTR(_top);
    _4current_file_no = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_4current_file_no))
        _4current_file_no = (long)DBL_PTR(_4current_file_no)->dbl;

    //     line_number        = top[LINE_NO]
    _2 = (int)SEQ_PTR(_top);
    _4line_number = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_4line_number))
        _4line_number = (long)DBL_PTR(_4line_number)->dbl;

    //     src_file           = top[FILE_PTR]
    _2 = (int)SEQ_PTR(_top);
    _11src_file = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_11src_file))
        _11src_file = (long)DBL_PTR(_11src_file)->dbl;

    //     file_start_sym     = top[FILE_START_SYM]
    _2 = (int)SEQ_PTR(_top);
    _4file_start_sym = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_4file_start_sym))
        _4file_start_sym = (long)DBL_PTR(_4file_start_sym)->dbl;

    //     OpWarning          = top[OP_WARNING]
    _2 = (int)SEQ_PTR(_top);
    _4OpWarning = (int)*(((s1_ptr)_2)->base + 5);
    if (!IS_ATOM_INT(_4OpWarning))
        _4OpWarning = (long)DBL_PTR(_4OpWarning)->dbl;

    //     OpTrace            = top[OP_TRACE]
    _2 = (int)SEQ_PTR(_top);
    _4OpTrace = (int)*(((s1_ptr)_2)->base + 6);
    if (!IS_ATOM_INT(_4OpTrace))
        _4OpTrace = (long)DBL_PTR(_4OpTrace)->dbl;

    //     OpTypeCheck        = top[OP_TYPE_CHECK]
    _2 = (int)SEQ_PTR(_top);
    _4OpTypeCheck = (int)*(((s1_ptr)_2)->base + 7);
    if (!IS_ATOM_INT(_4OpTypeCheck))
        _4OpTypeCheck = (long)DBL_PTR(_4OpTypeCheck)->dbl;

    //     OpProfileTime      = top[OP_PROFILE_TIME]
    _2 = (int)SEQ_PTR(_top);
    _4OpProfileTime = (int)*(((s1_ptr)_2)->base + 8);
    if (!IS_ATOM_INT(_4OpProfileTime))
        _4OpProfileTime = (long)DBL_PTR(_4OpProfileTime)->dbl;

    //     OpProfileStatement = top[OP_PROFILE_STATEMENT]
    _2 = (int)SEQ_PTR(_top);
    _4OpProfileStatement = (int)*(((s1_ptr)_2)->base + 9);
    if (!IS_ATOM_INT(_4OpProfileStatement))
        _4OpProfileStatement = (long)DBL_PTR(_4OpProfileStatement)->dbl;

    //     IncludeStk = IncludeStk[1..$-1]
    _1773 = SEQ_PTR(_11IncludeStk)->length;
    _1773 = _1773 - 1;
    rhs_slice_target = (object_ptr)&_11IncludeStk;
    RHS_Slice((s1_ptr)_11IncludeStk, 1, _1773);

    //     return TRUE
    DeRefDS(_top);
    return 1;
    ;
}


int _11MakeInt(int _text)
{
    int _num;
    int _1795 = 0;
    int _1794 = 0;
    int _1789;
    int _0, _1, _2;
    

    //     if length(text) > 9 then -- ensure no possibility of overflow  
    _1789 = SEQ_PTR(_text)->length;
    if (_1789 <= 9)
        goto L1;

    // 	return -1            -- use f.p. calculations  
    DeRefDSi(_text);
    return -1;
L1:

    //     num = text[1] - '0'
    _2 = (int)SEQ_PTR(_text);
    _1789 = (int)*(((s1_ptr)_2)->base + 1);
    _num = _1789 - 48;

    //     for i = 2 to length(text) do 
    _1789 = SEQ_PTR(_text)->length;
    { int _i;
        _i = 2;
L2:
        if (_i > _1789)
            goto L3;

        // 	num = num * 10 + (text[i] - '0')
        DeRef(_1794);
        if (_num == (short)_num)
            _1794 = _num * 10;
        else
            _1794 = NewDouble(_num * (double)10);
        DeRef(_1795);
        _2 = (int)SEQ_PTR(_text);
        _1795 = (int)*(((s1_ptr)_2)->base + _i);
        _1795 = _1795 - 48;
        if ((long)((unsigned long)_1795 +(unsigned long) HIGH_BITS) >= 0)
            _1795 = NewDouble((double)_1795);
        if (IS_ATOM_INT(_1794) && IS_ATOM_INT(_1795)) {
            _num = _1794 + _1795;
        }
        else {
            if (IS_ATOM_INT(_1794)) {
                _num = NewDouble((double)_1794 + DBL_PTR(_1795)->dbl);
            }
            else {
                if (IS_ATOM_INT(_1795)) {
                    _num = NewDouble(DBL_PTR(_1794)->dbl + (double)_1795);
                }
                else
                    _num = NewDouble(DBL_PTR(_1794)->dbl + DBL_PTR(_1795)->dbl);
            }
        }
        if (!IS_ATOM_INT(_num)) {
            _1 = (long)(DBL_PTR(_num)->dbl);
            DeRefDS(_num);
            _num = _1;
        }

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     return num
    DeRefDSi(_text);
    DeRef(_1795);
    DeRef(_1794);
    return _num;
    ;
}


int _11EscapeChar(int _c)
{
    int _0, _1, _2;
    

    //     if c = 'n' then
    if (_c != 110)
        goto L1;

    // 	return '\n'
    return 10;
    goto L2;
L1:

    //     elsif c = '\\' then
    if (_c != 92)
        goto L3;

    // 	return '\\'
    return 92;
    goto L2;
L3:

    //     elsif c = 't' then
    if (_c != 116)
        goto L4;

    // 	return '\t'
    return 9;
    goto L2;
L4:

    //     elsif c = '"' then
    if (_c != 34)
        goto L5;

    // 	return '"'
    return 34;
    goto L2;
L5:

    //     elsif c = '\''then
    if (_c != 39)
        goto L6;

    // 	return '\''
    return 39;
    goto L2;
L6:

    //     elsif c = 'r' then
    if (_c != 114)
        goto L7;

    // 	return '\r'
    return 13;
    goto L2;
L7:

    // 	CompileErr("unknown escape character")
    RefDS(_1804);
    _6CompileErr(_1804);
L2:
    ;
}


int _11my_sscanf(int _yytext)
{
    int _e_sign;
    int _ndigits;
    int _e_mag;
    int _mantissa = 0;
    int _c;
    int _i;
    int _dec = 0;
    int _1805 = 0;
    int _1813 = 0;
    int _0, _1, _2;
    

    //     if length(yytext) < 2 then
    _1805 = SEQ_PTR(_yytext)->length;
    if (_1805 >= 2)
        goto L1;

    // 	CompileErr("number not formed correctly")
    RefDS(_1807);
    _6CompileErr(_1807);
L1:

    //     mantissa = 0.0
    RefDS(_1808);
    DeRef(_mantissa);
    _mantissa = _1808;

    //     ndigits = 0
    _ndigits = 0;

    //     yytext &= 0 -- end marker
    Append(&_yytext, _yytext, 0);

    //     c = yytext[1]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + 1);

    //     i = 2
    _i = 2;

    //     while c >= '0' and c <= '9' do
L2:
    DeRef(_1805);
    _1805 = (_c >= 48);
    if (_1805 == 0) {
        goto L3;
    }
    DeRef(_1813);
    _1813 = (_c <= 57);
L4:
    if (_1813 == 0)
        goto L3;

    // 	ndigits += 1
    _ndigits = _ndigits + 1;

    // 	mantissa = mantissa * 10.0 + (c - '0')
    DeRef(_1813);
    _1813 = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_1815)->dbl);
    DeRef(_1805);
    _1805 = _c - 48;
    if ((long)((unsigned long)_1805 +(unsigned long) HIGH_BITS) >= 0)
        _1805 = NewDouble((double)_1805);
    DeRefDS(_mantissa);
    if (IS_ATOM_INT(_1805)) {
        _mantissa = NewDouble(DBL_PTR(_1813)->dbl + (double)_1805);
    }
    else
        _mantissa = NewDouble(DBL_PTR(_1813)->dbl + DBL_PTR(_1805)->dbl);

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 	i += 1
    _i = _i + 1;

    //     end while
    goto L2;
L3:

    //     if c = '.' then
    if (_c != 46)
        goto L5;

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 	i += 1
    _i = _i + 1;

    // 	dec = 10.0
    RefDS(_1815);
    DeRef(_dec);
    _dec = _1815;

    // 	while c >= '0' and c <= '9' do
L6:
    DeRef(_1805);
    _1805 = (_c >= 48);
    if (_1805 == 0) {
        goto L7;
    }
    DeRef(_1813);
    _1813 = (_c <= 57);
L8:
    if (_1813 == 0)
        goto L7;

    // 	    ndigits += 1
    _ndigits = _ndigits + 1;

    // 	    mantissa = mantissa + (c - '0') / dec
    DeRef(_1813);
    _1813 = _c - 48;
    if ((long)((unsigned long)_1813 +(unsigned long) HIGH_BITS) >= 0)
        _1813 = NewDouble((double)_1813);
    _0 = _1813;
    if (IS_ATOM_INT(_1813)) {
        _1813 = NewDouble((double)_1813 / DBL_PTR(_dec)->dbl);
    }
    else {
        _1813 = NewDouble(DBL_PTR(_1813)->dbl / DBL_PTR(_dec)->dbl);
    }
    DeRef(_0);
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl + DBL_PTR(_1813)->dbl);
    DeRef(_0);

    // 	    dec = dec * 10.0
    _0 = _dec;
    _dec = NewDouble(DBL_PTR(_dec)->dbl * DBL_PTR(_1815)->dbl);
    DeRefDS(_0);

    // 	    c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 	    i += 1
    _i = _i + 1;

    // 	end while
    goto L6;
L7:
L5:

    //     if ndigits = 0 then
    if (_ndigits != 0)
        goto L9;

    // 	return {}  -- no digits
    RefDS(_39);
    DeRefDSi(_yytext);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_1805);
    DeRef(_1813);
    return _39;
L9:

    //     if c = 'e' or c = 'E' then
    DeRef(_1813);
    _1813 = (_c == 101);
    if (_1813 != 0) {
        goto LA;
    }
    DeRef(_1805);
    _1805 = (_c == 69);
LB:
    if (_1805 == 0)
        goto LC;
LA:

    // 	e_sign = +1
    _e_sign = 1;

    // 	e_mag = 0
    _e_mag = 0;

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 	i += 1
    _i = _i + 1;

    // 	if c = '-' then
    if (_c != 45)
        goto LD;

    // 	    e_sign = -1
    _e_sign = -1;
    goto LE;
LD:

    // 	elsif c != '+' then
    if (_c == 43)
        goto LF;

    // 	    i -= 1
    _i = _i - 1;
LF:
LE:

    // 	c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 	i += 1
    _i = _i + 1;

    // 	if c >= '0' and c <= '9' then
    DeRef(_1805);
    _1805 = (_c >= 48);
    if (_1805 == 0) {
        goto L10;
    }
    DeRef(_1813);
    _1813 = (_c <= 57);
L11:
    if (_1813 == 0)
        goto L10;

    // 	    e_mag = c - '0'
    _e_mag = _c - 48;

    // 	    c = yytext[i]
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 	    i += 1
    _i = _i + 1;

    // 	    while c >= '0' and c <= '9' do
L12:
    DeRef(_1813);
    _1813 = (_c >= 48);
    if (_1813 == 0) {
        goto L13;
    }
    DeRef(_1805);
    _1805 = (_c <= 57);
L14:
    if (_1805 == 0)
        goto L13;

    // 		e_mag = e_mag * 10 + c - '0'
    DeRef(_1805);
    if (_e_mag == (short)_e_mag)
        _1805 = _e_mag * 10;
    else
        _1805 = NewDouble(_e_mag * (double)10);
    _0 = _1805;
    if (IS_ATOM_INT(_1805)) {
        _1805 = _1805 + _c;
        if ((long)((unsigned long)_1805 + (unsigned long)HIGH_BITS) >= 0) 
            _1805 = NewDouble((double)_1805);
    }
    else {
        _1805 = NewDouble(DBL_PTR(_1805)->dbl + (double)_c);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1805)) {
        _e_mag = _1805 - 48;
    }
    else {
        _e_mag = NewDouble(DBL_PTR(_1805)->dbl - (double)48);
    }
    if (!IS_ATOM_INT(_e_mag)) {
        _1 = (long)(DBL_PTR(_e_mag)->dbl);
        DeRefDS(_e_mag);
        _e_mag = _1;
    }

    // 		c = yytext[i]                          
    _2 = (int)SEQ_PTR(_yytext);
    _c = (int)*(((s1_ptr)_2)->base + _i);

    // 		i += 1
    _i = _i + 1;

    // 		if e_mag > 1000 then -- avoid int overflow. can only have 
    if (_e_mag <= 1000)
        goto L12;

    // 		    exit             -- 200-digit mantissa to reduce mag
    goto L13;
L15:

    // 	    end while
    goto L12;
L16:
    goto L13;
L10:

    // 	    return {} -- no exponent
    RefDS(_39);
    DeRefDSi(_yytext);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_1805);
    DeRef(_1813);
    return _39;
L13:

    // 	e_mag = e_sign * e_mag
    _e_mag = _e_sign * _e_mag;

    // 	if e_mag > 308 then
    if (_e_mag <= 308)
        goto L17;

    // 	    mantissa = mantissa * power(10.0, 308.0)
    DeRef(_1805);
    _1805 = Dpower(DBL_PTR(_1815), DBL_PTR(_1864));
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_1805)->dbl);
    DeRef(_0);

    // 	    e_mag = e_mag - 308
    _e_mag = _e_mag - 308;

    // 	    while e_mag > 0 do
L18:
    if (_e_mag <= 0)
        goto L19;

    // 		mantissa = mantissa * 10.0 -- Could crash? No we'll get INF.
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_1815)->dbl);
    DeRef(_0);

    // 		e_mag -= 1
    _e_mag = _e_mag - 1;

    // 	    end while
    goto L18;
L1A:
    goto L19;
L17:

    // 	    mantissa = mantissa * power(10.0, e_mag)
    DeRef(_1805);
    temp_d.dbl = (double)_e_mag;
    _1805 = Dpower(DBL_PTR(_1815), &temp_d);
    _0 = _mantissa;
    _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_1805)->dbl);
    DeRef(_0);
L19:
LC:

    //     return mantissa
    DeRefDSi(_yytext);
    DeRef(_dec);
    DeRef(_1805);
    DeRef(_1813);
    return _mantissa;
    ;
}


int _11Scanner()
{
    int _ch;
    int _i;
    int _sp;
    int _yytext = 0;
    int _d = 0;
    int _tok = 0;
    int _is_int;
    int _class;
    int _name = 0;
    int _1873 = 0;
    int _1877 = 0;
    int _0, _1, _2;
    

    //     while TRUE do
L1:

    // 	ch = ThisLine[bp]  -- getch inlined (in all the "hot" spots)
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 	bp += 1
    _6bp = _6bp + 1;

    // 	while ch = ' ' or ch = '\t' do
L2:
    DeRef(_1873);
    _1873 = (_ch == 32);
    if (_1873 != 0) {
        goto L3;
    }
    DeRef(_1877);
    _1877 = (_ch == 9);
L4:
    if (_1877 == 0)
        goto L5;
L3:

    // 	    ch = ThisLine[bp]  -- getch inlined
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 	    bp += 1
    _6bp = _6bp + 1;

    // 	end while
    goto L2;
L5:

    // 	if ch = 0 then
    if (_ch != 0)
        goto L6;

    // 	    bad_zero()
    _11bad_zero();
L6:

    // 	class = char_class[ch]
    _2 = (int)SEQ_PTR(_11char_class);
    _class = (int)*(((s1_ptr)_2)->base + _ch);

    // 	if class = LETTER then 
    if (_class != -2)
        goto L7;

    // 	    sp = bp
    _sp = _6bp;

    // 	    ch = ThisLine[bp]  -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 	    bp += 1 
    _6bp = _6bp + 1;

    // 	    if ch = 0 then
    if (_ch != 0)
        goto L8;

    // 		bad_zero()
    _11bad_zero();
L8:

    // 	    while id_char[ch] do
L9:
    DeRef(_1877);
    _2 = (int)SEQ_PTR(_11id_char);
    _1877 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1877 == 0)
        goto LA;

    // 		ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 		bp += 1
    _6bp = _6bp + 1;

    // 		if ch = 0 then
    if (_ch != 0)
        goto L9;

    // 		    bad_zero()
    _11bad_zero();
LB:

    // 	    end while
    goto L9;
LA:

    // 	    yytext = ThisLine[sp-1..bp-2]
    DeRef(_1877);
    _1877 = _sp - 1;
    if ((long)((unsigned long)_1877 +(unsigned long) HIGH_BITS) >= 0)
        _1877 = NewDouble((double)_1877);
    DeRef(_1873);
    _1873 = _6bp - 2;
    rhs_slice_target = (object_ptr)&_yytext;
    RHS_Slice((s1_ptr)_6ThisLine, _1877, _1873);

    // 	    bp -= 1  -- ungetch
    _6bp = _6bp - 1;

    // 	    tok = keyfind(yytext, -1)
    RefDS(_yytext);
    _0 = _tok;
    _tok = _10keyfind(_yytext, -1);
    DeRef(_0);

    // 	    if tok[T_ID] = NAMESPACE then
    _2 = (int)SEQ_PTR(_tok);
    _1873 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1873);
    if (binary_op_a(NOTEQ, _1873, 523))
        goto LC;

    // 		ch = getch()
    _ch = _11getch();

    // 		while ch = ' ' or ch = '\t' do
LD:
    DeRef(_1873);
    _1873 = (_ch == 32);
    if (_1873 != 0) {
        goto LE;
    }
    DeRef(_1877);
    _1877 = (_ch == 9);
LF:
    if (_1877 == 0)
        goto L10;
LE:

    // 		    ch = getch()
    _ch = _11getch();

    // 		end while
    goto LD;
L10:

    // 		if ch = ':' then
    if (_ch != 58)
        goto L11;

    // 		    ch = getch()
    _ch = _11getch();

    // 		    while ch = ' ' or ch = '\t' do
L12:
    DeRef(_1877);
    _1877 = (_ch == 32);
    if (_1877 != 0) {
        goto L13;
    }
    DeRef(_1873);
    _1873 = (_ch == 9);
L14:
    if (_1873 == 0)
        goto L15;
L13:

    // 			ch = getch()
    _ch = _11getch();

    // 		    end while
    goto L12;
L15:

    // 		    yytext = ""
    RefDS(_39);
    DeRefi(_yytext);
    _yytext = _39;

    // 		    while id_char[ch] do
L16:
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_11id_char);
    _1873 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1873 == 0)
        goto L17;

    // 			yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 			ch = getch()
    _ch = _11getch();

    // 		    end while 
    goto L16;
L17:

    // 		    ungetch()
    _11ungetch();

    // 		    if length(yytext) = 0 then
    DeRef(_1873);
    _1873 = SEQ_PTR(_yytext)->length;
    if (_1873 != 0)
        goto L18;

    // 			CompileErr("an identifier is expected here")
    RefDS(_1913);
    _6CompileErr(_1913);
L18:

    // 		    tok = keyfind(yytext, SymTab[tok[T_SYM]][S_OBJ]) 
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_tok);
    _1873 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_1873);
    _0 = _1873;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_1873))
        _1873 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1873)->dbl));
    else
        _1873 = (int)*(((s1_ptr)_2)->base + _1873);
    RefDS(_1873);
    DeRef(_0);
    _0 = _1873;
    _2 = (int)SEQ_PTR(_1873);
    _1873 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1873);
    DeRefDS(_0);
    RefDS(_yytext);
    Ref(_1873);
    _0 = _tok;
    _tok = _10keyfind(_yytext, _1873);
    DeRefDS(_0);

    // 		    if tok[T_ID] = VARIABLE then
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_tok);
    _1873 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1873);
    if (binary_op_a(NOTEQ, _1873, -100))
        goto L19;

    // 			tok[T_ID] = QUALIFIED_VARIABLE
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 515;
    DeRef(_1);
    goto L1A;
L19:

    // 		    elsif tok[T_ID] = FUNC then
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_tok);
    _1873 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1873);
    if (binary_op_a(NOTEQ, _1873, 501))
        goto L1B;

    // 			tok[T_ID] = QUALIFIED_FUNC
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 524;
    DeRef(_1);
    goto L1A;
L1B:

    // 		    elsif tok[T_ID] = PROC then
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_tok);
    _1873 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1873);
    if (binary_op_a(NOTEQ, _1873, 27))
        goto L1C;

    // 			tok[T_ID] = QUALIFIED_PROC
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 525;
    DeRef(_1);
    goto L1A;
L1C:

    // 		    elsif tok[T_ID] = TYPE then
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_tok);
    _1873 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_1873);
    if (binary_op_a(NOTEQ, _1873, 504))
        goto L1A;

    // 			tok[T_ID] = QUALIFIED_TYPE
    _2 = (int)SEQ_PTR(_tok);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _tok = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 526;
    DeRef(_1);
L1D:
L1E:
    goto L1A;
L11:

    // 		    ungetch()
    _11ungetch();
L1A:
LC:

    // 	    return tok
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_name);
    DeRef(_1873);
    DeRef(_1877);
    return _tok;
    goto L1;
L7:

    // 	elsif class <= ILLEGAL_CHAR then
    if (_class > -20)
        goto L1F;

    // 	    return {class, 0}  -- brackets, punctuation, eof, illegal char etc.
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _class;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L1F:

    // 	elsif class = NEWLINE then
    if (_class != -6)
        goto L20;

    // 	    if start_include then
    if (_11start_include == 0)
        goto L21;

    // 		IncludePush()
    _11IncludePush();
L21:

    // 	    read_line()
    _11read_line();
    goto L1;
L20:

    // 	elsif class = EQUALS then
    if (_class != 3)
        goto L22;

    // 	    return {class, 0}  
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _class;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L22:

    // 	elsif class = DOT or class = DIGIT then
    DeRef(_1873);
    _1873 = (_class == -3);
    if (_1873 != 0) {
        goto L23;
    }
    DeRef(_1877);
    _1877 = (_class == -7);
L24:
    if (_1877 == 0)
        goto L25;
L23:

    // 	    if class = DOT then
    if (_class != -3)
        goto L26;

    // 		if getch() = '.' then
    _0 = _1877;
    _1877 = _11getch();
    DeRef(_0);
    if (_1877 != 46)
        goto L27;

    // 		    return {SLICE, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 516;
    ((int *)_2)[2] = 0;
    _1877 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1873);
    return _1877;
    goto L28;
L27:

    // 		    ungetch()
    _11ungetch();
L28:
L26:

    // 	    is_int = TRUE
    _is_int = 1;

    // 	    yytext = {ch}
    _0 = _yytext;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _ch;
    _yytext = MAKE_SEQ(_1);
    DeRefi(_0);

    // 	    if ch = '.' then
    if (_ch != 46)
        goto L29;

    // 		is_int = FALSE
    _is_int = 0;
L29:

    // 	    ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 	    if ch = 0 then
    if (_ch != 0)
        goto L2A;

    // 		bad_zero()
    _11bad_zero();
L2A:

    // 	    bp += 1
    _6bp = _6bp + 1;

    // 	    while char_class[ch] = DIGIT do 
L2B:
    DeRef(_1877);
    _2 = (int)SEQ_PTR(_11char_class);
    _1877 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1877 != -7)
        goto L2C;

    // 		yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 		ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 		if ch = 0 then
    if (_ch != 0)
        goto L2D;

    // 		    bad_zero()
    _11bad_zero();
L2D:

    // 		bp += 1
    _6bp = _6bp + 1;

    // 	    end while
    goto L2B;
L2C:

    // 	    if ch = '.' then
    if (_ch != 46)
        goto L2E;

    // 		ch = getch()
    _ch = _11getch();

    // 		if ch = '.' then
    if (_ch != 46)
        goto L2F;

    // 		    ungetch()
    _11ungetch();
    goto L30;
L2F:

    // 		    is_int = FALSE
    _is_int = 0;

    // 		    if yytext[1] = '.' then
    DeRef(_1877);
    _2 = (int)SEQ_PTR(_yytext);
    _1877 = (int)*(((s1_ptr)_2)->base + 1);
    if (_1877 != 46)
        goto L31;

    // 			CompileErr("only one decimal point allowed")
    RefDS(_1954);
    _6CompileErr(_1954);
    goto L32;
L31:

    // 			yytext &= '.'
    Append(&_yytext, _yytext, 46);
L32:

    // 		    if char_class[ch] = DIGIT then
    DeRef(_1877);
    _2 = (int)SEQ_PTR(_11char_class);
    _1877 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1877 != -7)
        goto L33;

    // 			yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 			ch = getch()
    _ch = _11getch();

    // 			while char_class[ch] = DIGIT do
L34:
    DeRef(_1877);
    _2 = (int)SEQ_PTR(_11char_class);
    _1877 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1877 != -7)
        goto L35;

    // 			    yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 			    ch = getch()
    _ch = _11getch();

    // 			end while
    goto L34;
L36:
    goto L35;
L33:

    // 			CompileErr("fractional part of number is missing")
    RefDS(_1964);
    _6CompileErr(_1964);
L35:
L30:
L2E:

    // 	    if ch = 'e' or ch = 'E' then
    DeRef(_1877);
    _1877 = (_ch == 101);
    if (_1877 != 0) {
        goto L37;
    }
    DeRef(_1873);
    _1873 = (_ch == 69);
L38:
    if (_1873 == 0)
        goto L39;
L37:

    // 		is_int = FALSE
    _is_int = 0;

    // 		yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 		ch = getch()
    _ch = _11getch();

    // 		if ch = '-' or ch = '+' or char_class[ch] = DIGIT then
    DeRef(_1873);
    _1873 = (_ch == 45);
    if (_1873 != 0) {
        _1873 = 1;
        goto L3A;
    }
    DeRef(_1877);
    _1877 = (_ch == 43);
    _1873 = (_1877 != 0);
L3A:
    if (_1873 != 0) {
        goto L3B;
    }
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_11char_class);
    _1873 = (int)*(((s1_ptr)_2)->base + _ch);
    _1873 = (_1873 == -7);
L3C:
    if (_1873 == 0)
        goto L3D;
L3B:

    // 		    yytext &= ch
    Append(&_yytext, _yytext, _ch);
    goto L3E;
L3D:

    // 		    CompileErr("exponent not formed correctly")
    RefDS(_1977);
    _6CompileErr(_1977);
L3E:

    // 		ch = getch()
    _ch = _11getch();

    // 		while char_class[ch] = DIGIT do
L3F:
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_11char_class);
    _1873 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1873 != -7)
        goto L40;

    // 		    yytext &= ch
    Append(&_yytext, _yytext, _ch);

    // 		    ch = getch()
    _ch = _11getch();

    // 		end while
    goto L3F;
L40:
L39:

    // 	    bp -= 1  --ungetch
    _6bp = _6bp - 1;

    // 	    i = MakeInt(yytext)
    RefDS(_yytext);
    _i = _11MakeInt(_yytext);

    // 	    if is_int and i != -1 then
    if (_is_int == 0) {
        goto L41;
    }
    DeRef(_1877);
    _1877 = (_i != -1);
L42:
    if (_1877 == 0)
        goto L41;

    // 		return {ATOM, NewIntSym(i)}
    _0 = _1877;
    _1877 = _10NewIntSym(_i);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1877;
    _1877 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1873);
    return _1877;
    goto L1;
L41:

    // 		d = my_sscanf(yytext)
    RefDS(_yytext);
    _0 = _d;
    _d = _11my_sscanf(_yytext);
    DeRef(_0);

    // 		if sequence(d) then
    DeRef(_1877);
    _1877 = 0;
    if (_1877 == 0)
        goto L43;

    // 		    CompileErr("number not formed correctly")
    RefDS(_1807);
    _6CompileErr(_1807);
    goto L1;
L43:

    // 		elsif is_int and d <= MAXINT_DBL then
    if (_is_int == 0) {
        goto L44;
    }
    DeRef(_1873);
    if (IS_ATOM_INT(_d)) {
        _1873 = (_d <= 1073741823);
    }
    else {
        _1873 = (DBL_PTR(_d)->dbl <= (double)1073741823);
    }
L45:
    if (_1873 == 0)
        goto L44;

    // 		    return {ATOM, NewIntSym(d)}  -- 1 to 1.07 billion
    Ref(_d);
    _0 = _1873;
    _1873 = _10NewIntSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L44:

    // 		    return {ATOM, NewDoubleSym(d)}
    Ref(_d);
    _0 = _1873;
    _1873 = _10NewDoubleSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L46:
L47:
    goto L1;
L25:

    // 	elsif class = MINUS then
    if (_class != 10)
        goto L48;

    // 	    ch = ThisLine[bp] -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 	    bp += 1
    _6bp = _6bp + 1;

    // 	    if ch = '-' then 
    if (_ch != 45)
        goto L49;

    // 		if start_include then
    if (_11start_include == 0)
        goto L4A;

    // 		    IncludePush()
    _11IncludePush();
L4A:

    // 		read_line()
    _11read_line();
    goto L1;
L49:

    // 	    elsif ch = '=' then
    if (_ch != 61)
        goto L4B;

    // 		return {MINUS_EQUALS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 519;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L4B:

    // 		bp -= 1
    _6bp = _6bp - 1;

    // 		return {MINUS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 10;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L4C:
    goto L1;
L48:

    // 	elsif class = DOUBLE_QUOTE then
    if (_class != -4)
        goto L4D;

    // 	    ch = ThisLine[bp]  -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 	    bp += 1
    _6bp = _6bp + 1;

    // 	    yytext = ""
    RefDS(_39);
    DeRefi(_yytext);
    _yytext = _39;

    // 	    while ch != '\n' and ch != '\r' do -- can't be EOF
L4E:
    DeRef(_1873);
    _1873 = (_ch != 10);
    if (_1873 == 0) {
        goto L4F;
    }
    DeRef(_1877);
    _1877 = (_ch != 13);
L50:
    if (_1877 == 0)
        goto L4F;

    // 		if ch = '"' then 
    if (_ch != 34)
        goto L51;

    // 		    exit
    goto L4F;
    goto L52;
L51:

    // 		elsif ch = '\\' then
    if (_ch != 92)
        goto L53;

    // 		    yytext &= EscapeChar(getch())
    _0 = _1877;
    _1877 = _11getch();
    DeRef(_0);
    _1877 = _11EscapeChar(_1877);
    Append(&_yytext, _yytext, _1877);
    goto L52;
L53:

    // 		elsif ch = '\t' then
    if (_ch != 9)
        goto L54;

    // 		    CompileErr("tab character found in string - use \\t instead")
    RefDS(_2017);
    _6CompileErr(_2017);
    goto L52;
L54:

    // 		elsif ch = 0 then
    if (_ch != 0)
        goto L55;

    // 		    bad_zero()
    _11bad_zero();
    goto L52;
L55:

    // 		    yytext &= ch
    Append(&_yytext, _yytext, _ch);
L52:

    // 		ch = ThisLine[bp]  -- getch
    _2 = (int)SEQ_PTR(_6ThisLine);
    _ch = (int)*(((s1_ptr)_2)->base + _6bp);

    // 		bp += 1
    _6bp = _6bp + 1;

    // 	    end while
    goto L4E;
L4F:

    // 	    if ch = '\n' or ch = '\r' then
    DeRef(_1877);
    _1877 = (_ch == 10);
    if (_1877 != 0) {
        goto L56;
    }
    DeRef(_1873);
    _1873 = (_ch == 13);
L57:
    if (_1873 == 0)
        goto L58;
L56:

    // 		CompileErr("end of line reached with no closing \"")
    RefDS(_2025);
    _6CompileErr(_2025);
L58:

    // 	    return {STRING, NewStringSym(yytext)}
    RefDS(_yytext);
    _0 = _1873;
    _1873 = _10NewStringSym(_yytext);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 503;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefDSi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L4D:

    // 	elsif class = PLUS then
    if (_class != 11)
        goto L59;

    // 	    ch = getch()
    _ch = _11getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L5A;

    // 		return {PLUS_EQUALS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 518;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L5A:

    // 		ungetch()
    _11ungetch();

    // 		return {PLUS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 11;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L5B:
    goto L1;
L59:

    // 	elsif class = CONCAT then
    if (_class != 15)
        goto L5C;

    // 	    ch = getch()
    _ch = _11getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L5D;

    // 		return {CONCAT_EQUALS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 522;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L5D:

    // 		ungetch()
    _11ungetch();

    // 		return {CONCAT, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 15;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L5E:
    goto L1;
L5C:

    // 	elsif class = NUMBER_SIGN then
    if (_class != -11)
        goto L5F;

    // 	    i = 0
    _i = 0;

    // 	    is_int = -1
    _is_int = -1;

    // 	    while i < MAXINT_VAL/32 do             
L60:
    DeRef(_1873);
    _1873 = (1073741823 % 32) ? NewDouble((double)1073741823 / 32) : (1073741823 / 32);
    if (binary_op_a(GREATEREQ, _i, _1873))
        goto L61;

    // 		ch = getch()
    _ch = _11getch();

    // 		if char_class[ch] = DIGIT then
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_11char_class);
    _1873 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1873 != -7)
        goto L62;

    // 		    i = i * 16 + ch - '0'
    if (_i == (short)_i)
        _1873 = _i * 16;
    else
        _1873 = NewDouble(_i * (double)16);
    _0 = _1873;
    if (IS_ATOM_INT(_1873)) {
        _1873 = _1873 + _ch;
        if ((long)((unsigned long)_1873 + (unsigned long)HIGH_BITS) >= 0) 
            _1873 = NewDouble((double)_1873);
    }
    else {
        _1873 = NewDouble(DBL_PTR(_1873)->dbl + (double)_ch);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_1873)) {
        _i = _1873 - 48;
    }
    else {
        _i = NewDouble(DBL_PTR(_1873)->dbl - (double)48);
    }
    if (!IS_ATOM_INT(_i)) {
        _1 = (long)(DBL_PTR(_i)->dbl);
        DeRefDS(_i);
        _i = _1;
    }

    // 		    is_int = TRUE
    _is_int = 1;
    goto L60;
L62:

    // 		elsif ch >= 'A' and ch <= 'F' then   
    DeRef(_1873);
    _1873 = (_ch >= 65);
    if (_1873 == 0) {
        goto L61;
    }
    DeRef(_1877);
    _1877 = (_ch <= 70);
L63:
    if (_1877 == 0)
        goto L61;

    // 		    i = (i * 16) + ch - ('A'-10)
    DeRef(_1877);
    if (_i == (short)_i)
        _1877 = _i * 16;
    else
        _1877 = NewDouble(_i * (double)16);
    _0 = _1877;
    if (IS_ATOM_INT(_1877)) {
        _1877 = _1877 + _ch;
        if ((long)((unsigned long)_1877 + (unsigned long)HIGH_BITS) >= 0) 
            _1877 = NewDouble((double)_1877);
    }
    else {
        _1877 = NewDouble(DBL_PTR(_1877)->dbl + (double)_ch);
    }
    DeRef(_0);
    DeRef(_1873);
    _1873 = 55;
    if (IS_ATOM_INT(_1877)) {
        _i = _1877 - 55;
    }
    else {
        _i = NewDouble(DBL_PTR(_1877)->dbl - (double)55);
    }
    if (!IS_ATOM_INT(_i)) {
        _1 = (long)(DBL_PTR(_i)->dbl);
        DeRefDS(_i);
        _i = _1;
    }

    // 		    is_int = TRUE
    _is_int = 1;
    goto L60;
L64:

    // 		    exit 
    goto L61;
L65:

    // 	    end while
    goto L60;
L61:

    // 	    if is_int = -1 then
    if (_is_int != -1)
        goto L66;

    // 		if ch = '!' then
    if (_ch != 33)
        goto L67;

    // 		    if line_number > 1 then
    if (_4line_number <= 1)
        goto L68;

    // 			CompileErr(
    RefDS(_2057);
    _6CompileErr(_2057);
L68:

    // 		    shebang = ThisLine
    Ref(_6ThisLine);
    DeRefi(_11shebang);
    _11shebang = _6ThisLine;

    // 		    if start_include then
    if (_11start_include == 0)
        goto L69;

    // 			IncludePush()
    _11IncludePush();
L69:

    // 		    read_line()
    _11read_line();
    goto L1;
L67:

    // 		    CompileErr("hex number not formed correctly")
    RefDS(_2058);
    _6CompileErr(_2058);
L6A:
    goto L1;
L66:

    // 		if i >= MAXINT_VAL/32 then
    DeRef(_1873);
    _1873 = (1073741823 % 32) ? NewDouble((double)1073741823 / 32) : (1073741823 / 32);
    if (binary_op_a(LESS, _i, _1873))
        goto L6B;

    // 		    d = i
    DeRef(_d);
    _d = _i;

    // 		    is_int = FALSE
    _is_int = 0;

    // 		    while TRUE do
L6C:

    // 			ch = getch()  -- eventually END_OF_FILE_CHAR or new-line 
    _ch = _11getch();

    // 			if char_class[ch] = DIGIT then
    DeRef(_1873);
    _2 = (int)SEQ_PTR(_11char_class);
    _1873 = (int)*(((s1_ptr)_2)->base + _ch);
    if (_1873 != -7)
        goto L6D;

    // 			    d = (d * 16) + ch - '0'
    if (IS_ATOM_INT(_d)) {
        if (_d == (short)_d)
            _1873 = _d * 16;
        else
            _1873 = NewDouble(_d * (double)16);
    }
    else {
        _1873 = NewDouble(DBL_PTR(_d)->dbl * (double)16);
    }
    _0 = _1873;
    if (IS_ATOM_INT(_1873)) {
        _1873 = _1873 + _ch;
        if ((long)((unsigned long)_1873 + (unsigned long)HIGH_BITS) >= 0) 
            _1873 = NewDouble((double)_1873);
    }
    else {
        _1873 = NewDouble(DBL_PTR(_1873)->dbl + (double)_ch);
    }
    DeRef(_0);
    DeRef(_d);
    if (IS_ATOM_INT(_1873)) {
        _d = _1873 - 48;
        if ((long)((unsigned long)_d +(unsigned long) HIGH_BITS) >= 0)
            _d = NewDouble((double)_d);
    }
    else {
        _d = NewDouble(DBL_PTR(_1873)->dbl - (double)48);
    }
    goto L6C;
L6D:

    // 			elsif ch >= 'A' and ch <= 'F' then   
    DeRef(_1873);
    _1873 = (_ch >= 65);
    if (_1873 == 0) {
        goto L6E;
    }
    DeRef(_1877);
    _1877 = (_ch <= 70);
L6F:
    if (_1877 == 0)
        goto L6E;

    // 			    d = (d * 16) + ch - ('A'- 10)
    DeRef(_1877);
    if (IS_ATOM_INT(_d)) {
        if (_d == (short)_d)
            _1877 = _d * 16;
        else
            _1877 = NewDouble(_d * (double)16);
    }
    else {
        _1877 = NewDouble(DBL_PTR(_d)->dbl * (double)16);
    }
    _0 = _1877;
    if (IS_ATOM_INT(_1877)) {
        _1877 = _1877 + _ch;
        if ((long)((unsigned long)_1877 + (unsigned long)HIGH_BITS) >= 0) 
            _1877 = NewDouble((double)_1877);
    }
    else {
        _1877 = NewDouble(DBL_PTR(_1877)->dbl + (double)_ch);
    }
    DeRef(_0);
    DeRef(_1873);
    _1873 = 55;
    DeRef(_d);
    if (IS_ATOM_INT(_1877)) {
        _d = _1877 - 55;
        if ((long)((unsigned long)_d +(unsigned long) HIGH_BITS) >= 0)
            _d = NewDouble((double)_d);
    }
    else {
        _d = NewDouble(DBL_PTR(_1877)->dbl - (double)55);
    }
    goto L6C;
L70:

    // 			    exit 
    goto L6E;
L71:

    // 		    end while
    goto L6C;
L6E:
L6B:

    // 		ungetch()
    _11ungetch();

    // 		if is_int then
    if (_is_int == 0)
        goto L72;

    // 		    return {ATOM, NewIntSym(i)}
    _0 = _1873;
    _1873 = _10NewIntSym(_i);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L72:

    // 		    if d <= MAXINT_DBL then            -- d is always >= 0
    if (binary_op_a(GREATER, _d, 1073741823))
        goto L73;

    // 			return {ATOM, NewIntSym(d)} 
    Ref(_d);
    _0 = _1873;
    _1873 = _10NewIntSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L73:

    // 			return {ATOM, NewDoubleSym(d)}
    Ref(_d);
    _0 = _1873;
    _1873 = _10NewDoubleSym(_d);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L74:
L75:
L76:
    goto L1;
L5F:

    // 	elsif class = MULTIPLY then
    if (_class != 13)
        goto L77;

    // 	    ch = getch()
    _ch = _11getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L78;

    // 		return {MULTIPLY_EQUALS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 520;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L78:

    // 		ungetch()
    _11ungetch();

    // 		return {MULTIPLY, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 13;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L79:
    goto L1;
L77:

    // 	elsif class = DIVIDE then
    if (_class != 14)
        goto L7A;

    // 	    ch = getch()
    _ch = _11getch();

    // 	    if ch = '=' then
    if (_ch != 61)
        goto L7B;

    // 		return {DIVIDE_EQUALS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 521;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L7B:

    // 		ungetch()
    _11ungetch();

    // 		return {DIVIDE, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 14;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L7C:
    goto L1;
L7A:

    // 	elsif class = SINGLE_QUOTE then
    if (_class != -5)
        goto L7D;

    // 	    ch = getch()
    _ch = _11getch();

    // 	    if ch = '\\' then 
    if (_ch != 92)
        goto L7E;

    // 		ch = EscapeChar(getch())
    _0 = _1873;
    _1873 = _11getch();
    DeRef(_0);
    _ch = _11EscapeChar(_1873);
    goto L7F;
L7E:

    // 	    elsif ch = '\t' then
    if (_ch != 9)
        goto L80;

    // 		CompileErr("tab character found in string - use \\t instead")
    RefDS(_2017);
    _6CompileErr(_2017);
    goto L7F;
L80:

    // 	    elsif ch = '\'' then
    if (_ch != 39)
        goto L81;

    // 		CompileErr("single-quote character is empty")
    RefDS(_2098);
    _6CompileErr(_2098);
L81:
L7F:

    // 	    if getch() != '\'' then
    _0 = _1873;
    _1873 = _11getch();
    DeRef(_0);
    if (_1873 == 39)
        goto L82;

    // 		CompileErr("character constant is missing a closing '")
    RefDS(_2101);
    _6CompileErr(_2101);
L82:

    // 	    return {ATOM, NewIntSym(ch)}
    _0 = _1873;
    _1873 = _10NewIntSym(_ch);
    DeRef(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 502;
    ((int *)_2)[2] = _1873;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L7D:

    // 	elsif class = LESS then
    if (_class != 1)
        goto L83;

    // 	    if getch() = '=' then
    _0 = _1873;
    _1873 = _11getch();
    DeRef(_0);
    if (_1873 != 61)
        goto L84;

    // 		return {LESSEQ, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 5;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L84:

    // 		ungetch()
    _11ungetch();

    // 		return {LESS, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L85:
    goto L1;
L83:

    // 	elsif class = GREATER then
    if (_class != 6)
        goto L86;

    // 	    if getch() = '=' then
    _0 = _1873;
    _1873 = _11getch();
    DeRef(_0);
    if (_1873 != 61)
        goto L87;

    // 		return {GREATEREQ, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 2;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L87:

    // 		ungetch()
    _11ungetch();

    // 		return {GREATER, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 6;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L88:
    goto L1;
L86:

    // 	elsif class = BANG then
    if (_class != -1)
        goto L89;

    // 	    if getch() = '=' then 
    _0 = _1873;
    _1873 = _11getch();
    DeRef(_0);
    if (_1873 != 61)
        goto L8A;

    // 		return {NOTEQ, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 4;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L8A:

    // 		ungetch()
    _11ungetch();

    // 		return {BANG, 0}
    DeRef(_1873);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
L8B:
    goto L1;
L89:

    // 	elsif class = KEYWORD then
    if (_class != -10)
        goto L8C;

    // 	    return {keylist[ch - KEYWORD_BASE][K_TOKEN], 0}
    DeRef(_1873);
    _1873 = _ch - 128;
    _2 = (int)SEQ_PTR(_8keylist);
    _1873 = (int)*(((s1_ptr)_2)->base + _1873);
    RefDS(_1873);
    _0 = _1873;
    _2 = (int)SEQ_PTR(_1873);
    _1873 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_1873);
    DeRefDS(_0);
    _0 = _1873;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _1873;
    Ref(_1873);
    ((int *)_2)[2] = 0;
    _1873 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRef(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L8C:

    // 	elsif class = BUILTIN then
    if (_class != -9)
        goto L8D;

    // 	    name = keylist[ch - BUILTIN_BASE + NUM_KEYWORDS][K_NAME]
    DeRef(_1873);
    _1873 = _ch - 170;
    if ((long)((unsigned long)_1873 +(unsigned long) HIGH_BITS) >= 0)
        _1873 = NewDouble((double)_1873);
    _0 = _1873;
    if (IS_ATOM_INT(_1873)) {
        _1873 = _1873 + 24;
    }
    else {
        _1873 = NewDouble(DBL_PTR(_1873)->dbl + (double)24);
    }
    DeRef(_0);
    _0 = _1873;
    _2 = (int)SEQ_PTR(_8keylist);
    if (!IS_ATOM_INT(_1873))
        _1873 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_1873)->dbl));
    else
        _1873 = (int)*(((s1_ptr)_2)->base + _1873);
    RefDS(_1873);
    DeRef(_0);
    DeRef(_name);
    _2 = (int)SEQ_PTR(_1873);
    _name = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_name);

    // 	    return keyfind(name, -1)
    RefDS(_name);
    _0 = _1873;
    _1873 = _10keyfind(_name, -1);
    DeRefDS(_0);
    DeRefi(_yytext);
    DeRef(_d);
    DeRef(_tok);
    DeRefDS(_name);
    DeRef(_1877);
    return _1873;
    goto L1;
L8D:

    // 	    InternalErr("Scanner()")  
    RefDS(_2130);
    _6InternalErr(_2130);
L8E:

    //    end while
    goto L1;
L8F:
    ;
}


