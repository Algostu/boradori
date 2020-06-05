
            if((*sharks)[i]->getCol() == (*sharks)[j]->getCol() && (*sharks)[i]->getRow() == (*sharks)[j]->getRow()){
                if((*sharks)[i]->getSize() > (*sharks)[j]->getSize()) {
                    (*sharks)[j]->DeleteShark();
                }
                else {
                    (*sharks)[i]->DeleteShark();
                }
            }
        }
    }
}

void PrintShark(vector<Shark*> sharks){
    for (auto &&shark : sharks)
    {
        printf("Shark : %d %d %d %d %d\n",shark->getRow(),shark->getCol(),shark->getSpeed(),shark->getDirect(),shark->getSize());
    }
};