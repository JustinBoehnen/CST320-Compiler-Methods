PROGRAM test4a;
VAR
    a : integer;
FUNCTION foo( par1 : integer; par2 : real) : integer;
    VAR
        a,b : char;
        c,d : integer;
    FUNCTION bar( par1, par2 : char; par3 : integer) : integer;
        VAR
            a,b : char;
            c,d : integer;
        BEGIN
            par3 := par1 + par2 + a + b + c + d;
            bar := c + d;
        END;
    BEGIN
        par2 := par1 + a + b + c + d;
        foo := bar(1,2,3) + c + d;
    END;
BEGIN
    a := foo(a, 3.2);
END.

