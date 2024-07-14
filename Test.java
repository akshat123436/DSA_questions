class T {
    protected int x, y;
}

class Test {
    public static void main(String args[]) {
        String str="()()(())";
        int n = str.length();
        int left =0, right = 0;
        for(int i = 0;i<n;i++){
            if(str.charAt(i) == '('){
                left++;
            }
            else if(str.charAt(i) == ')'){
                right++;
            }
            if(right > left) return "0";
        }
        if(right == left) return "1";
        return "0";
    }

    
}