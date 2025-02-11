class Esfera
{
    public:
        void pegaOpcao(int opcao);
        void pegaDiametro(double diametro);
        int devolveOpcao();
        double devolveDiametro();
        double calculaRaio();
        double calculaArea();
        double calculaVolume();
    private:
        int opcao;
        double diametro;
        double raio;
};