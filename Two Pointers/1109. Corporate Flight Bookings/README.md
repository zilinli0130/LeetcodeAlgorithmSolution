# 1109. Corporate Flight Bookings

###### Tag: Prefix Sum

###### Time: O(N)
###### Space: O(N)

We could define `diff[i] = flightSeat[i] - flightSeat[i-1]`. For each flight booking, we could conclude that `diff[booking[0]] += booking[2]` and `diff[booking[1] + 1] -= booking[2]`. For the flights between `booking[0]` and `booking[1]`, their `diff[i]` would remain the same at the current booking so far. After that, we could loop through all the `diff[i]` to find out the 
`flightSeat[i]` iteratively.