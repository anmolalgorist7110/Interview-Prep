/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
   
     var curr = init
   
    //inc function
    function increment(){
         return curr += 1 
    }

    //dec func 
    function  decrement(){
        return  curr -= 1 
    }

    //reset val
    function reset(){
        return curr = init 
    }

    return{
        increment,
        decrement,
        reset
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */