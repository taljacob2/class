#include "Class1.h"

void print(Class1 *class1) { printf("x = %d\n", class1->x); }

void addOneToX(Class1 *class1) { class1->x += 1; }

void *Class1Destructor(Class1 *class1) {
    if (class1 == NULL) { return NULL; }

    class1->CLASS_ALLOCATION_TABLE->allocationAddressList
            ->deleteNodeThatHasTheGivenData(
                    class1->CLASS_ALLOCATION_TABLE->allocationAddressList,
                    class1);

    free(class1->thisObjectBase);

    // Destruct self.
    free(class1);

    return NULL;
}

void constructor_Class1_fields(Class1 *class1) {
    class1->thisObjectBase = ObjectBaseConstructor();

    static Constructable const constructable = {
            .constructor = (void *(*const)(void) )(&Class1Constructor)};
    class1->thisObjectBase->constructable = &constructable;

    static Destructable const destructable = {
            .destructor = (void *(*const)(void *) )(&Class1Destructor)};
    class1->thisObjectBase->destructable = &destructable;

    class1->x         = 1;
    class1->print     = &print;
    class1->addOneToX = &addOneToX;
}

Class1 *Class1Constructor() {
    Class1 *obj = malloc(sizeof *obj);
    if (obj == NULL) { /* error handling here */
    }

    constructor_Class1_fields(obj);

    obj->thisObjectBase->CLASS_NAME = "Class1";
    obj->CLASS_ALLOCATION_TABLE =
            getLegacy_AllocationTableList()
                    ->findLegacy_AllocationTableByClassName(
                            obj->thisObjectBase->CLASS_NAME);
    if (obj->CLASS_ALLOCATION_TABLE == NULL) {
        obj->CLASS_ALLOCATION_TABLE =
                Legacy_AllocationTableConstructorWithClassName(
                        (char *) obj->thisObjectBase->CLASS_NAME);

        // Create a legacy_node that its data points to `obj->CLASS_ALLOCATION_TABLE`.
        Legacy_Node *nodeThatItsDataPointsClassAllocationTable =
                Legacy_NodeConstructorWithDataAndDataSize(
                        obj->CLASS_ALLOCATION_TABLE,
                        sizeof(Legacy_AllocationTable *));

        // Add this legacy_node to `GLOBAL_ALLOCATION_TABLE_LIST->legacy_allocationTableList`.
        getLegacy_AllocationTableList()->allocationTableList->add(
                getLegacy_AllocationTableList()->allocationTableList,
                nodeThatItsDataPointsClassAllocationTable);
    }

    // Create a legacy_node that its data points to the "pointer of `obj`".
    Legacy_Node *nodeThatItsDataPointsToThePointerOfObj =
            Legacy_NodeConstructorWithDataAndDataSize(obj, sizeof(void *));

    // Add this legacy_node to `obj->CLASS_ALLOCATION_TABLE->allocationAddressList`.
    obj->CLASS_ALLOCATION_TABLE->allocationAddressList->add(
            obj->CLASS_ALLOCATION_TABLE->allocationAddressList,
            nodeThatItsDataPointsToThePointerOfObj);

    return obj;
}
