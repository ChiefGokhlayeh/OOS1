enum class class1 { DIETER, HANS, PETER, KAI };
enum class sports { FUSSBALL, BASKETBALL, HOCKEY };

int main(void)
{
    int i;
    sports mysport;
    mysport = sports::FUSSBALL;
    mysport = static_cast<sports>(static_cast<int>(sports::FUSSBALL) + 1);
    mysport = static_cast<sports>(1);
    mysport = static_cast<sports>(10);
    mysport = static_cast<sports>(static_cast<int>(mysport) + 1);
    mysport = sports(static_cast<sports>(static_cast<int>(mysport) + 1));
    float f;
    for (i = static_cast<int>(sports::FUSSBALL); i <= static_cast<int>(sports::HOCKEY); i++)
        mysport = sports(i);
    for (int k = static_cast<int>(sports::FUSSBALL); k <= static_cast<int>(sports::HOCKEY); k++)
        mysport = sports(k);
    return 0;
}
