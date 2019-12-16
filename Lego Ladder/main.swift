
var arr: [Int] = [Int]();
var dp: [[Int]] = [[Int]] (repeating: [Int] (repeating: -1, count: (1 << 15) + 1), count: 2)
var n: Int = 0;

func solve (number: Int, turn: Bool) -> Bool
{
    if (lose (number: number))
    {
        dp [turn ? 1 : 0][number] = turn ? 0 : 1;
        return !turn
    }
    if dp [turn ? 1 : 0][number] != -1
    {
        return dp [turn ? 1 : 0][number] == 1;
    }
    if (turn)
    {
        for x in 0..<n
        {
            if ((number >> x)&1 == 1)
            {
                let result = solve (number: number & (~(1 << x)), turn: !turn);
                if (result)
                {
                    dp [turn ? 1 : 0][number] = 1;
                    return true;
                }
            }
        }
        dp [turn ? 1 : 0][number] = 0;
        return false;
    }
    for x in 0..<n
    {
        if ((number >> x)&1 == 1)
        {
            let result = solve (number: number & (~(1 << x)), turn: !turn);
            if (!result)
            {
                dp [turn ? 1 : 0][number] = 0;
                return false;
            }
        }
    }
    dp [turn ? 1 : 0][number] = 1;
    return true;
}

func lose (number: Int) -> Bool
{
    var num = number;
    var prev = 0;
    var curr = 0;
    var cnt = 0;
    var cnt2 = 0;
    var decreasing = -1;
    while (num != 0)
    {
        if ((num&1) == 1)
        {
            prev = curr;
            curr = arr [n - cnt - 1];
            cnt2 += 1;
            if (cnt2 > 2)
            {
                if (decreasing == 0 && prev > curr)
                {
                    return false;
                }
                else if (decreasing == 1 && prev < curr)
                {
                    return false;
                }
            }
            if (cnt2 > 1)
            {
                if (prev > curr)
                {
                    decreasing = 1;
                }
                else if (prev < curr)
                {
                    decreasing = 0;
                }
            }
        }
        num = (num >> 1);
        cnt += 1;
    }
    return true;
}

for _ in 0..<5
{
    for _ in 0..<3
    {
        if let something = readLine ()
        {
            let this = something.split {$0 == " "};
            if let l = Int (this [0])
            {
                n = l;
                arr = [Int] ();
                dp = [[Int]] (repeating: [Int] (repeating: -1, count: (1 << 15) + 1), count: 2);
                let line = readLine()!.split {$0 == " "};
                for x in 0..<n
                {
                    arr.append (Int(line [x])!);
                }
                let i = solve(number: ((1 << n) - 1), turn: true);
                if (i)
                {
                    print("A", separator: "", terminator: "");
                }
                else
                {
                    print ("B", separator: "", terminator: "");
                }
            }
        }
    }
    print ()
}



