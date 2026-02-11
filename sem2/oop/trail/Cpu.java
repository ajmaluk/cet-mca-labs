class Cpu {
    int price;
    Cpu(int price) {
        this.price = price; 
    }
    class Processor {
        int cores;
        String manufacturer;

        Processor(int cores, String manufacturer){
            this.manufacturer = manufacturer;
            this.cores = cores;
        }

        void displayProcessor() {
            System.out.println("Processor Information : ");
            System.out.println("No of Cores : "+ cores);
            System.out.println("Manufacturer : "+ manufacturer);
        }
    }
    static class Ram {
        int memory;
        String manufacturer;

        Ram(int memory,String manufacturer) {
            this.memory = memory;
            this.manufacturer = manufacturer;
        }
            
        void displayMemory() {
            System.out.println("Memory Information : ");
            System.out.println("Memory : "+ memory);
            System.out.println("Manufacturer : "+ manufacturer);
        }
    }

    public static void main(String[] args) {
        Cpu cpu = new Cpu(5500);
        System.out.println("Cpu Prize :  : "+ cpu.price);

        Cpu.Processor processor = cpu.new Processor(8, "Intel");

        processor.displayProcessor();

        Cpu.Ram ram = new Cpu.Ram(16,"Xpu");

        ram.displayMemory();
    }
}
