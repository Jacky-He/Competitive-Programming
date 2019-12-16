var n: Int = Int(readLine(strippingNewline: true)!)!
var t: Int = Int(readLine(strippingNewline: true)!)!
var arr = [Int]()
for _ in 0..<n
{
    arr.append(Int(readLine(strippingNewline: true)!)!)
}
arr.sort()
var i = 0
var j = t - 1
var result = Int.max
while j < n
{
    if ((arr [i] > 0 && arr [j] > 0) || (arr [i] < 0 && arr [j] < 0))
    {
        result = min (result, max (abs (arr [j]), abs (arr [i])))
    }
    else
    {
        result = min(min (result, abs (arr [j]) + abs(arr [i])*2), abs(arr [j])*2 + abs (arr [i]))
    }
    i += 1
    j += 1
}
print (result)


