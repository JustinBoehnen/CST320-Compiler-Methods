PROGRAM test4a;
VAR
    a : integer;
PROCEDURE foo( par1 : integer; par2 : real; par3 : char ) ;
    VAR
        a,b : char;
        c,d : integer;
    BEGIN
        par2 := par1 + a + b + c + d + par3;
    END;
BEGIN
    foo(a, 3.2*a, 5);
END.

