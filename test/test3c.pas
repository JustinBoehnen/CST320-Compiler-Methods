PROGRAM test3c;
TYPE
    arr1 = ARRAY[1..5] of integer;
    arr2 = ARRAY[2..6, 3..20, 0..4] of char;
VAR
    a : integer;
    b : arr1;
    c : integer;
    d : arr2;

BEGIN
    b[ 
       b[ 
          3 ] ] := 5;
    a := c;
    a := b[c];
    a := b[c] + b[ b[ b[c] ] ];
    b[a] := a + c;
    b[a] := d[3,a,c];
END.

