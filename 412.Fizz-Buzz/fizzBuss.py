class Solution:
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = [str(i) for i in range(1,n+1)]
        for i in result:
            num = int(i)
            if num%15 == 0:
                result[num-1] = "FizzBuzz"
            elif num%5 == 0:
                result[num-1] = "Buzz"
            elif num%3 == 0:
                result[num-1] = "Fizz"
        
        return result
