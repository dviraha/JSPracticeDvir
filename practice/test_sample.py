from sample import my_add

def test_my_add1():
    assert(my_add(1,2.6) == 6.2)

def test_my_add_fail():
    assert(my_add(1,2.4) == 6.2)
    
    


