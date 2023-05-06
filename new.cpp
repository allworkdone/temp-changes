Node *swapNodes(Node *head, int i, int j)
{
    // Write your code here
    if (i < 0 || j < 0)
    {
        return NULL;
    }
    if (head == NULL)
    {
        return head;
    }
    if (i == j)
    {
        return head;
    }
    else if ((i == 0 || j == 0) && (abs(i - j) == 1))
    {

        Node *c1 = head;
        Node *c2 = head->next;
        c1->next = c2->next;
        c2->next = c1;
        head = c2;
        return head;
    }
    else if (i != 0 && j != 0 && abs(i - j) == 1)
    {
        if (i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }
        Node *p1 = head;
        Node *p2 = head;
        Node *c1;
        Node *c2;
        int count = 0;
        while (count < i - 1)
        {
            p1 = p1->next;
            count++;
        }
        c1 = p1->next;
        count = 0;
        while (count < j - 1)
        {
            p2 = p2->next;
            count++;
        }
        c2 = p2->next;
        c1->next = c2->next;
        c2->next = c1;
        p1->next = c2;
    }

    // dikkatt...
    else if ((i == 0 || j == 0) && (abs(i - j) != 1))
    {
        if (i == 0)
        {
            Node *c1 = head;
            Node *c2;
            Node *p1 = head->next;
            Node *p2 = head;
            int count = 0;
            while (count < j - 1)
            {
                p2 = p2->next;
                count++;
            }
            c2 = p2->next;
            c1->next = c2->next;
            c2->next = p1;
            p2->next = c1;
            head = c2;
        }
        else
        {
            Node *c1 = head;
            Node *c2;
            Node *p1 = head->next;
            Node *p2 = head;
            int count = 0;
            while (count < i - 1)
            {
                p2 = p2->next;
                count++;
            }
            c2 = p2->next;
            c1->next = c2->next;
            c2->next = p1;
            p2->next = c1;
            head = c2;
        }
    }
    else
    {
        if (i > j)
        {
            int temp = i;
            i = j;
            j = temp;
        }
        int count = 0;
        Node *c1;
        Node *c2;
        Node *p1 = head;
        Node *p2 = head;
        while (count < i - 1)
        {
            p1 = p1->next;
            count++;
        }
        c1 = p1->next;
        count = 0;
        while (count < j - 1)
        {
            p2 = p2->next;
            count++;
        }
        c2 = p2->next;
        p1->next = c2;
        p2->next = c1;
        c1->next = c2->next;
        c2->next = p2;
    }
    return head;
}