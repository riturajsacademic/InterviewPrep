int maxArea(int* height, int heightSize) {
    int start = 0;
    int end = heightSize-1;
    int max = 0;
    int temp = 0;

    while (start != end) {
        temp = (end-start);
        if (height[start] < height[end]) {
            temp *= height[start];
            start++;
        } else {
            temp *= height[end];
            end--;
        }

        //
        // Check if max.
        //

        if (temp > max) {
            max = temp;
        }

    }

    return max;
}