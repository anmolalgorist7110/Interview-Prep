/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    //to be func
    function toBe(comp){
        if(val === comp){
          return true ;
        }else{
            throw new Error('Not Equal')
        }
    }

    //not to be func
    function notToBe(comp){
        if(val !== comp){
            return true ;
        }else{
            throw new Error("Equal")
        }
    }

    return{
        toBe,
        notToBe
    }

};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */