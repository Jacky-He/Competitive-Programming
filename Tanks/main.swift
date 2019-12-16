typealias ll = Int64;
typealias int = Int32
let line1 = readLine ()!.split {$0 == " "};
let n = Int (line1 [0])!;
let p = Int (line1 [1])!;
let m = Int (line1 [2])!;
var unitsDefense: [int] = [int] (repeating: 0, count: n);
var unitsResistance: [int] = [int] (repeating: 0, count: n);
var psaP: [ll] = [ll] (repeating: 0, count: p + 1);
var psaM: [ll] = [ll] (repeating: 0, count: m + 1);

for x in 0..<n
{
    let temp: [int] = readLine ()!.split (separator: " ").map {int($0)!};
    unitsDefense [x] = temp [0];
    unitsResistance [x] = temp [1];
}
var x = 0;
var attacksP = readLine ()!.split (separator: " ").map{ll($0)!};
var attacksM = readLine ()!.split (separator: " ").map{ll($0)!};
attacksP.sort();
attacksM.sort();
x = 1;
for each in attacksP
{
    psaP [x] = psaP [x - 1] + each;
    x += 1;
}
x = 1;
for each in attacksM
{
    psaM [x] = psaM [x - 1] + each;
    x += 1;
}
var actualindex = 0;
var actualresult = ll.max; //first: index, second: damage;
for y in 0..<n
{
    let defense = unitsDefense [y];
    let resistance = unitsResistance [y];
    var lo: Int = 1;
    var hi: Int = p;
    var total: ll = 0;
    var result: Int = 0;
    while lo + 1 < hi
    {
        let mid = (lo + hi)/2;
        if (attacksP [mid - 1] <= defense)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if (attacksP [hi - 1] <= defense)
    {
        result = hi;
    }
    else if (attacksP [lo - 1] <= defense)
    {
        result = lo;
    }
    total += (psaP [p] - psaP [result] - ll(defense)*ll(p - result));
    lo = 1;
    hi = m;
    result = 0;
    while lo + 1 < hi
    {
        let mid = (lo + hi)/2;
        if (attacksM [mid - 1] <= resistance)
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }
    if (attacksM [hi - 1] <= resistance)
    {
        result = hi;
    }
    else if (attacksM [lo - 1] <= resistance)
    {
        result = lo;
    }
    total += (psaM [m] - psaM [result] - ll(resistance)*ll(m - result));
    if actualresult > total
    {
        actualresult = total;
        actualindex = y + 1;
    }
}
print (actualindex);
