class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        // Map to store reserved seats for each row
        // Key: row number, Value: bitmask representing reserved seats
        unordered_map<int, int> rowReservations;


        // Build bitmask for each row with reserved seats
        // Bit position represents seat (10 - seatNumber) to align with mask checking
        for (auto& reservation : reservedSeats) {
            int row = reservation[0];
            int seatNumber = reservation[1];
            rowReservations[row] |= 1 << (10 - seatNumber);
        }

        // Define masks for three possible 4-seat group positions

        // Left group: seats 2-5 (0b0111100000)
        // Right group: seats 6-9 (0b0000011110)
        // Middle group: seats 4-7 (0b0001111000)
        int seatGroupMasks[3] = {0b0111100000, 0b0000011110, 0b0001111000};
      
        // Rows without any reservations can fit 2 families (left and right groups)
        int totalFamilies = (n - rowReservations.size()) * 2;
      
        // Check each row with reservations
        for (auto& [rowNumber, reservedBitmask] : rowReservations) {
            // Try to place families in available positions
            for (int& mask : seatGroupMasks) {
                // Check if the 4-seat group is completely available
                if ((reservedBitmask & mask) == 0) {
                    // Mark these seats as used to avoid double counting
                    reservedBitmask |= mask;
                    totalFamilies++;
                }
            }
        }
      
        return totalFamilies;
    }
};
