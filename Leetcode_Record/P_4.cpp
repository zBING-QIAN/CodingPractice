#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()<nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        else{
            int l1=0,l2=0,r1=nums1.size()-1,r2=nums2.size()-1;
            int  m_pos=(nums1.size()+nums2.size())/2,i=0;
            while(r2>=0){                
                i=(r2+l2)/2;
                if(nums1[m_pos-i-1]>nums2[i]){
                    if(i>=nums2.size()-1||nums1[m_pos-i-1]<=nums2[i+1]){
                        if((nums1.size()+nums2.size())%2)
                            return double(nums1[m_pos-i-1]);
                        else{
                            if(m_pos-i-2<0){
                                return double(nums1[m_pos-i-1]+nums2[i])/2.0;                                                 }
                            return double(((nums1[m_pos-i-2]<nums2[i])?nums2[i]:nums1[m_pos-i-2])+nums1[m_pos-i-1])/2.0;
                        }
                    }
                                               
                    l2=i+1;                    
             }
                else if(nums1[m_pos-i-1]<nums2[i]){ 
                    if(i==0&&m_pos==nums1.size())
                        return double(nums1[m_pos-i-1]+nums2[i])/2.0;
                    if(nums1[m_pos-i]>=nums2[i]){
                        if((nums1.size()+nums2.size())%2)
                            return double(nums2[i]);
                        else{
                            if(i==0){
                                return double(nums1[m_pos-i-1]+nums2[i])/2.0;                                                 }
                            return double(((nums1[m_pos-i-1]<nums2[i-1])?nums2[i-1]:nums1[m_pos-i-1])+nums2[i])/2.0;
                        }
                    }
                          
                    r2=i-1;                
                }
                else {
                    return double(nums2[i]);                    
                }
                
                
            }
            if((nums1.size()+nums2.size())%2)
                            return double(nums1[m_pos]);
            else{
                        
                 return double(nums1[m_pos-1]+nums1[m_pos])/2.0;                                            }
            
        }
    }
};