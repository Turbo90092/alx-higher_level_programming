#include <Python.h>
#include <stdio.h>

/**
 * print_python_float - gives data of the PyFloatObject
 * @p: the PyObject
 */
void print_python_float(PyObject *p)
{
    double value = 0;
    char *string = NULL;

    fflush(stdout);
    printf("[.] float object info\n");

    if (!PyFloat_CheckExact(p))
    {
        printf("  [ERROR] Invalid Float Object\n");
        return;
    }

    value = PyFloat_AS_DOUBLE(p);
    string = PyOS_double_to_string(value, 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
    printf("  value: %s\n", string);
    PyMem_Free(string);
}

/**
 * print_python_bytes - gives data of the PyBytesObject
 * @p: the PyObject
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size = 0, i = 0;
    char *string = NULL;

    fflush(stdout);
    printf("[.] bytes object info\n");

    if (!PyBytes_CheckExact(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    printf("  size: %zd\n", size);

    string = PyBytes_AS_STRING(p);
    printf("  trying string: %s\n", string);
    printf("  first %zd bytes:", size < 10 ? size + 1 : 10);

    for (i = 0; i < size + 1 && i < 10; i++)
    {
        printf(" %02hhx", string[i]);
    }

    printf("\n");
}

/**
 * print_python_list - gives data of the PyListObject
 * @p: the PyObject
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size = 0;
    PyObject *item;
    Py_ssize_t i = 0;

    fflush(stdout);
    printf("[*] Python list info\n");

    if (PyList_CheckExact(p))
    {
        size = PyList_GET_SIZE(p);
        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", ((PyListObject *)p)->allocated);

        for (i = 0; i < size; i++)
        {
            item = PyList_GET_ITEM(p, i);
            printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);

            if (PyBytes_Check(item))
                print_python_bytes(item);
            else if (PyFloat_Check(item))
                print_python_float(item);
        }
    }
    else
    {
        printf("  [ERROR] Invalid List Object\n");
    }
}
