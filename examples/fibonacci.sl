mem 0 +  1 .
mem 1 +  0 .
mem 2 +  0 .
mem 3 + 10 .

11 1 while dup2 > do
    mem 2 + mem 1 + , .
    mem 1 + mem 0 + , .
    mem 0 + mem 1 + , mem 2 + , + .
    inc
end

4 mem 1 sys_write