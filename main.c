#include "menus.h"
#include "ventas.h"

/*int main(){
  menuPrincipal();
  return 0;
}*/
int main()
{
  Venta v = capturarVenta();

  guardarVenta(v);

  mostrarVentas();
  return 0;
}*/