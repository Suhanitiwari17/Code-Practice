class Solution {
    public String addBinary(String a, String b) {
                StringBuilder ans=new StringBuilder();
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        while(i>=0 || j>=0){
            int count1s=carry;
            if(i>=0 && a.charAt(i)=='1') count1s++;
            if(j>=0 && b.charAt(j)=='1') count1s++;
            
            if(count1s==0){
                ans.append('0');
                carry=0;
            }
            if(count1s==1){
                ans.append('1');
                carry=0;
            }
            if(count1s==2){
                ans.append('0');
                carry=1;
            }
            if(count1s==3){
                ans.append('1');
                carry=1;
            }
            i--;
            j--;
        }
        if(carry==1){
            ans.append('1');//convert carry to string
        }
        ans.reverse();
        
        while(ans.length()>1 && ans.charAt(0)=='0'){
            ans.deleteCharAt(0);
        }
        
        return ans.toString();
    }
}