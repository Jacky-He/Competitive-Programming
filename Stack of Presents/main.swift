typealias int = Int32;
var n: int = int (readLine (strippingNewline: true)!)!;
var arr: [int] = [int]();
for _ in 0..<n
{
    arr.append (int (readLine (strippingNewline: true)!)!);
}
var currWeight: int = 0;
var cnt: int = 0;
for each in arr.sorted()
{
    if (each >= currWeight)
    {
        cnt += 1;
        currWeight += each;
    }
}
print (cnt);
