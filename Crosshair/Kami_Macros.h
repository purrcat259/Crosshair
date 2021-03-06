#ifndef KAMI_MACROS_H
#define KAMI_MACROS_H

// WARNING
// Macros are sensitive for "," (comma), "(", ")" (parenthese) and " " (space).
// Provide only the asked numbers of arguments, without additional commas and without spaces beetween commas.
// Example:
//      PUSH_ALL(_units, [_unit] call getPlayersAroundUnit);
//      This will work as intended.
//      PUSH_ALL(_units, [_unit, 100] call getPlayersAroundUnit);
//      This won't work, as the macro identifies 100 as a third parameter.
//      Use AS_ARRAY_* instead of passing actual arrays.
//      PUSH_ALL(_units, AS_ARRAY_2(_unit, 100) call getPlayersAroundUnit);

// Creates private declaritions for arguments.
// Example:
//      GIVEN:
//      WHEN:
//          PVT_3(_unit,_group,_trigger); 
//      THEN:
//          private ["_unit","_group","_trigger"];

#define PVT_1(VAR1) private #VAR1
#define PVT_2(VAR1,VAR2) private [#VAR1,#VAR2]
#define PVT_3(VAR1,VAR2,VAR3) private [#VAR1,#VAR2,#VAR3]
#define PVT_4(VAR1,VAR2,VAR3,VAR4) private [#VAR1,#VAR2,#VAR3,#VAR4]
#define PVT_5(VAR1,VAR2,VAR3,VAR4,VAR5) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5]
#define PVT_6(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6]
#define PVT_7(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6,#VAR7]
#define PVT_8(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6,#VAR7,#VAR8]
#define PVT_9(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9) private [#VAR1,#VAR2,#VAR3,#VAR4,#VAR5,#VAR6,#VAR7,#VAR8,#VAR9]


// Creates array selection for arguments. Only works if the array is a variable!
// Example:
//      GIVEN:
//          _strings = ["unit", "group", "trigger"];
//      WHEN:
//          SELECT_3(_strings,_unit,_group,_trigger); 
//      THEN:
//          _unit == "unit";
//          _group == "group";
//          _trigger == "trigger";

#define SELECT_1(ARRAY,VAR1) VAR1 = (ARRAY) select 0
#define SELECT_2(ARRAY,VAR1,VAR2) SELECT_1(ARRAY,VAR1); VAR2 = (ARRAY) select 1
#define SELECT_3(ARRAY,VAR1,VAR2,VAR3) SELECT_2(ARRAY,VAR1,VAR2); VAR3 = (ARRAY) select 2
#define SELECT_4(ARRAY,VAR1,VAR2,VAR3,VAR4) SELECT_3(ARRAY,VAR1,VAR2,VAR3); VAR4 = (ARRAY) select 3
#define SELECT_5(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5) SELECT_4(ARRAY,VAR1,VAR2,VAR3,VAR4); VAR5 = (ARRAY) select 4
#define SELECT_6(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6) SELECT_5(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5); VAR6 = (ARRAY) select 5
#define SELECT_7(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7) SELECT_6(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6); VAR7 = (ARRAY) select 6
#define SELECT_8(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8) SELECT_7(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7); VAR8 = (ARRAY) select 7
#define SELECT_9(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9) SELECT_8(ARRAY,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8); VAR9 = (ARRAY) select 8

// Creates private declarations and selection from _this array for arguments.
// Recommended for function/script argument processing.
// Example:
//      GIVEN:
//          _this = ["unit", "group", "trigger"];
//      WHEN:
//          FUN_ARGS_3(_unit,_group,_trigger);
//      THEN:
//          private ["_unit","_group","_trigger"];
//          _unit == "unit";
//          _group == "group";
//          _trigger == "trigger";
#define FUN_ARGS_1(VAR1) \
    PVT_1(VAR1); \
    SELECT_1(_this,VAR1)
    
#define FUN_ARGS_2(VAR1,VAR2) \
    PVT_2(VAR1,VAR2); \
    SELECT_2(_this,VAR1,VAR2)
    
#define FUN_ARGS_3(VAR1,VAR2,VAR3) \
    PVT_3(VAR1,VAR2,VAR3); \
    SELECT_3(_this,VAR1,VAR2,VAR3)
    
#define FUN_ARGS_4(VAR1,VAR2,VAR3,VAR4) \
    PVT_4(VAR1,VAR2,VAR3,VAR4); \
    SELECT_4(_this,VAR1,VAR2,VAR3,VAR4)
    
#define FUN_ARGS_5(VAR1,VAR2,VAR3,VAR4,VAR5) \
    PVT_5(VAR1,VAR2,VAR3,VAR4,VAR5); \
    SELECT_5(_this,VAR1,VAR2,VAR3,VAR4,VAR5)
    
#define FUN_ARGS_6(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6) \
    PVT_6(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6); \
    SELECT_6(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6)
    
#define FUN_ARGS_7(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7) \
    PVT_7(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7); \
    SELECT_7(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7)
    
#define FUN_ARGS_8(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8) \
    PVT_8(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8); \
    SELECT_8(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8)
    
#define FUN_ARGS_9(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9) \
    PVT_9(VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9); \
    SELECT_9(_this,VAR1,VAR2,VAR3,VAR4,VAR5,VAR6,VAR7,VAR8,VAR9)

// Adds a value to the end of an array.
// Example:
//      GIVEN:
//          _numbers = [1, 3, 5, 1];
//          _number = 1;
//      WHEN:
//          PUSH(_numbers, _number);
//      THEN:
//          _numbers == [1, 3, 5, 1, 1];
#define PUSH(ARRAY,VAL) (ARRAY) set [count (ARRAY), (VAL)]

// Adds all values from one array to another.
// Example:
//      GIVEN:
//          _numbers = [5, 9, 6];
//          _otherNumbers = [1, 3, 8];
//      WHEN:
//          PUSH_ALL(_numbers, _otherNumbers);
//      THEN:
//          _numbers == [5, 9, 6, 1, 3, 8];
#define PUSH_ALL(TO,FROM) { PUSH(TO,_x); } foreach (FROM)

// Filters the FROM array with a condition and adds the values that return true to the TO array.
// The values from the FROM array can be referenced by variable "_x".
// Example:
//      GIVEN:
//          _numbers = [];
//          _otherNumbers = [1, 2, 3, 6, 8];
//          _condition = {_x % 2 == 0};
//      WHEN:
//          FILTER_PUSH_ALL(_numbers, _otherNumbers, _condition);
//      THEN:
//          _numbers == [2, 6, 8];
#define FILTER_PUSH_ALL(TO,FROM,COND) { if (call COND) then { PUSH(TO,_x); }; } foreach (FROM)

// Selects a random value from an array.
// Example:
//      GIVEN:
//          _behaviours = ['AWARE', 'SAFE'];
//      WHEN:
//          _random = SELECT_RAND(_behaviours);
//      THEN:
//          _random == 'AWARE' or _random == 'AWARE'
#define SELECT_RAND(ARRAY) (ARRAY) select (floor (random (count (ARRAY))))

// Adds 1 to the variable.
// Example:
//      GIVEN:
//          _i = 0;
//      WHEN:
//          INC(_i);
//      THEN:
//          _i == 1;
#define INC(VAR) VAR = VAR + 1

// Subtracts 1 from the variable.
// Example:
//      GIVEN:
//          _i = 3;
//      WHEN:
//          DEC(_i);
//      THEN:
//          _i == 2;
#define DEC(VAR) VAR = VAR - 1

// Creates an array from given arguments.
// Example:
//      GIVEN:
//      WHEN:
//          _array = AS_ARRAY_2('AWARE','SAFE');
//      THEN:
//          _array == ['AWARE', 'SAFE'];
#define AS_ARRAY_1(VAL1) [VAL1]
#define AS_ARRAY_2(VAL1,VAL2) [VAL1,VAL2]
#define AS_ARRAY_3(VAL1,VAL2,VAL3) [VAL1,VAL2,VAL3]
#define AS_ARRAY_4(VAL1,VAL2,VAL3,VAL4) [VAL1,VAL2,VAL3,VAL4]
#define AS_ARRAY_5(VAL1,VAL2,VAL3,VAL4,VAL5) [VAL1,VAL2,VAL3,VAL4,VAL5]

// Returns the longest axis of trigger.
// Example:
//      GIVEN:
//          _trigger = trigger;
//          triggerArea _trigger == [300, 400, -31.2, false];
//      WHEN:
//          _longestAxis = LONGEST_AXIS(_trigger);
//      THEN:
//          _longestAxis == 400;
#define LONGEST_AXIS(TRG) (if ((triggerArea (TRG)) select 0 > (triggerArea (TRG)) select 1) then {(triggerArea (TRG)) select 0} else {(triggerArea (TRG)) select 1})

// Creates a private declaration for a variable and enables instant assigment.
// Example:
//      GIVEN:
//      WHEN:
//          DECLARE(_group) = _x;
//      THEN:
//          private "_group"; _group = _x;
#define DECLARE(VAR) private #VAR; VAR

#endif //KAMI_MACROS_H