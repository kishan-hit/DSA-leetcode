class Solution {
    public int findMinArrowShots(int[][] points) {
        int cnt=1;
        Arrays.sort(points,(a,b)->Integer.compare(a[1],b[1]));
        int i=0,j=1;
        while(j<points.length){
            if(points[i][1]<points[j][0]){
                ++cnt;
                i=j;
            }
            ++j;
        }
        return cnt;
    }
}