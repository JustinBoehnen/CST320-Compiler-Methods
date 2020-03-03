PROGRAM test3;
TYPE
    arr1 = ARRAY[1..5] of integer;
VAR
    a : integer;
    b : arr1;
    c : integer;

BEGIN
    a := c;
    a := b[2];
    b[3] := a + c;
END.

