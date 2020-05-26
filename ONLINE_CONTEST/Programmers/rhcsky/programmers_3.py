class Skill():
    def __init__(self,parent,child,point):
        self.parent = parent
        self.child = child
        self.point = point

def solution(total_sp, skills):

    skill_array = []
    for skill in skills:
        skill_array.append(Skill(skill[0],skill[1],0))

    for skill in skill_array:
        



    answer = []
    return answer


solution(121,[[1, 2], [1, 3], [3, 6], [3, 4], [3, 5]])